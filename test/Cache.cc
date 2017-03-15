#include "Cache.h"
using namespace std;
void NS_ASSERT_MSG(bool condition, string str){
    if (!condition)cout<<"NS_ASSERT_MSG"<<str<<endl;
    assert(condition);
}

string CacheModule::get_file_hits(){
    std::stringstream ss;
    string s="";
    ss << log_file_hits.size();
    s+= "_cache | hit_files:"+ ss.str() +"\t";
    for (map<string , uint32_t>::iterator it=log_file_hits.begin();it!=log_file_hits.end();++it){
        ss.str(std::string());
        ss<<it->second;
        s+=it->first+":"+ss.str()+",";
    }
    s+="\n\n";
    log_file_hits.clear();

    return s;
    }
    

uint32_t CacheModule::get_file_requests(const string &_filename, const string& _ID){
    string key = _filename;
    key = key + "-";
    key.append(_ID);
    map<string, uint32_t>::iterator lit = log_file_requests.find(key);
    if (lit!=log_file_requests.end()){
        if(lit->second == 1){// it is not first time to access data  has been cached
            return 1;
        }else if(lit->second > 1){//it is first time to access data has been cached
            return lit->second - 1;
        }
    }
    return 1;
}

void CacheModule::increase_file_requests(const string &_filename, const string& _ID){
    string key = _filename;
    key = key + "-";
    key.append(_ID);
    map<string, uint32_t>::iterator lit = log_file_requests.find(key);
    if (lit!=log_file_requests.end())
        lit->second++;
    else{
        log_file_requests[key] = 1;
    }
}

void CacheModule::clear_file_requests(const string &_filename, const string& _ID){
    string key = _filename;
    key = key + "-";
    key.append(_ID);
    map<string, uint32_t>::iterator lit = log_file_requests.find(key);
    if (lit != log_file_requests.end()){
        log_file_requests.erase(lit);
    }
}

    

    
    

void LRU_Table::add_object(LRU_Object* obj){
    /* first item in cache */
    if (stored_files == 0){
        obj->next = NULL;
        obj->prev = NULL;
        head = obj;
        tail = obj;
        stored_files=1;
        }
    else{
        stored_files++;
        update_object(obj, true);    
        }
        
        objects.insert (std::pair<string,LRU_Object*>(obj->filename, obj));
    }
    
void LRU_Table::remove_object(const LRU_Object* obj){
    /* first cache is empty  (maybe this check is redundant) */
    if (stored_files == 0){
        return;
        }
    else if (stored_files == 1){
        /* head and tail is the same obj*/
        head = NULL;
        tail = NULL;
        stored_files = 0;
        }
    else{
        /* if obj is  tail*/
        if(obj == tail){
            obj->next->prev = NULL;
            tail = obj->next;
            stored_files--;
        }else{
            // remove head
            if(obj->next == NULL){
                head = obj->prev;
                obj->prev->next = NULL;
            }else{
                obj->next->prev = obj->prev;
                NS_ASSERT_MSG(obj->prev, "LRU_Table::remove_object.Error. The poiter is NULL");
                obj->prev->next = obj->next;
            }
            stored_files--;
        }
    }
    objects.erase(obj->filename);
    delete obj;    
}
    
/**
 *  sets object as head
 */
void LRU_Table::update_object(LRU_Object* obj, bool new_object){
    
    if (new_object){
        head->next = obj;
        obj->prev = head;
        head = obj;
        }
    else if (stored_files > 1 && head!=obj){
        
        if (tail == obj){
            tail = obj->next;
            obj->next->prev = NULL;
            }
        else{
            obj->next->prev = obj->prev;
            obj->prev->next = obj->next;
            }
        obj->next = NULL;
        obj->prev = head;
        head->next = obj;
        head = obj;
        }
    }

pair<bool, int> Slot_Object::insert_packet(const string& key, 
                                           uint32_t _ID, 
                                           char *payload){
    Name2index::iterator it;
    uint32_t pos = 0;
    string _filename;
    int cnt = 0;
    it = name2index.find(key);
    //1.The file named key was  cached partly!, 
    //cache its packet without checkout order.
    if(it != name2index.end()){
        pos = it->second;
        Pkts::iterator vt = files[pos].begin();
        assert((_ID - vt->first) < PKT_NUM);
           //"Slot_Object::insert_packet, Internal error, out-of-order"
            //<< _ID << " " << vt->first);
        assert(files[pos].size() <= PKT_NUM);
           //"Slot_Object::insert_packet, Internal error,"
            //<< "files can not be more than PKT_NUM");
        files[pos].insert(Pkts::value_type(_ID, payload));
        cnt++;
        return std::make_pair(true, cnt);
     }

     //2.The file named key was not cached!, and this slot is full.
    if(files.size() >= file_num){
        /* Delete the oldest file, or in options, 
         * we can use LRU algorithm to delete file
           Note: it's worthy to discuss if we should 
           delete the corresponding elements in bloom filter, 
        */
        NS_ASSERT_MSG(files[cur_index].size() != 0, "File is empty");
        cnt -= files[cur_index].size();
        files[cur_index].clear();
        files[cur_index].insert(Pkts::value_type(_ID, payload)); 
        cnt++;
        //Find old corresponding element in name2index, and erase it
        for (Name2index::iterator it_t=name2index.begin(); 
             it_t!=name2index.end(); it_t++){
            if(it_t->second == cur_index) {
                name2index.erase(it_t);
                break;
            }
        }
        //insert new element into name2index
        name2index.insert(Name2index::value_type(key, cur_index));

//cout<<"The files is full"<<endl;
        // increment cur_index to can delete  the oldest file
        cur_index++;
        if(cur_index >= file_num) cur_index = 0;
        return std::make_pair(true, cnt);
    }

    // 3.The file named key was not  cached!, and this slot is not full
    Pkts p;
    // Get the pos after insert one element into files
    pos = files.size();
    p.insert(Pkts::value_type(_ID, payload));
    files.push_back(p);
    cnt++;
    name2index.insert(Name2index::value_type(key, pos));
    return std::make_pair(true, cnt);
}

pair<bool, int> Slot_Object::insert_packets(const string& key, 
                                            uint32_t last_id,
                                            Pkts pkts){
    int cnt = 0;
    checkout_file(key, last_id); 
    //insert packets to dram
    for (Pkts::iterator it = pkts.begin(); it != pkts.end(); it++){
        pair<bool, int> pr = insert_packet(key, it->first, it->second);
        NS_ASSERT_MSG(pr.first, "Internal error,insert_packet is failed");
        cnt += pr.second;
    }
    return std::make_pair(true, cnt);
}

inline void Slot_Object::checkout_file(const string &key, uint32_t last_id){
    uint32_t pos = 0, ID = 0, len = 0;
    pos = key.find("-");
    NS_ASSERT_MSG(pos,"Key format is error!");
    ID = atoi(key.substr(pos+1).c_str());
    len = last_id - ID + 1;
    assert(len <= PKT_NUM);
    //"Internal error,"
                 //<< last_id << "-" << ID 
                 //<< ",len can not be more than  PKT_NUM");
}

pair<bool, Pkts> Slot_Object::find(const string& key){
    Pkts p;
    Name2index::iterator it = name2index.find(key);
    if(it == name2index.end()) return std::make_pair(false, p);
    return std::make_pair(true, files[it->second]);
}


int32_t S_Cache::remove_last_file_r(){
    string key = LRU->tail->filename;
    int32_t removed_packets = get_stored_packets_r(key);
    if (removed_packets == -1)
        return -1;
    cache_table_r.erase(key);
    LRU->remove_object(LRU->tail);
    //cout<<"S_Cache removed last file "<<key<<endl;
    return removed_packets;
}

int32_t S_Cache::get_stored_packets_r(const string& _filename){
    Cachetable::iterator it = cache_table_r.find(_filename);
    if (it != cache_table_r.end()){
        return it->second.size();
    }else{
        return -1;
    }
}


void S_Cache::log_file_hit(const string& _filename, const string& _ID){
    string key = _filename+"-";
    key.append(_ID);
    map<string, uint32_t>::iterator lit = log_file_hits.find(key);
    if (lit!=log_file_hits.end())
        lit->second++;
    else{
        log_file_hits[key]=1;
    }
}

//if return value >0:found,  <0: forward, 
//delete  packet after read to make room for residual data block from DRAM
int32_t S_Cache::get_readcached_packet2(const string& key, uint32_t ID){
    Cachetable::iterator cit = cache_table_r.find(key);
    if(cit != cache_table_r.end()){
        Pkts::iterator pit = cit->second.begin();
        //drop first packet,it is for compatibility with S_Cache::get_readcached_packet
        if(key.substr(key.rfind("-")+1) == std::to_string(ID-1) && pit->first == (ID-1)){
            cit->second.erase(pit);
            readcache_pcks--;
            pit = cit->second.begin();
        }
        if(ID != pit->first){
            return -1;
        }
        cit->second.erase(pit);
        readcache_pcks--;

        if(cit->second.size() == 0) {
            cache_table_r.erase(cit);
            LRU->remove_object(LRU->objects[key]);
        }else{
            LRU->update_object(LRU->objects[key]);
        }
         
        uint32_t req = get_file_requests(key.substr(0, key.rfind("-")), 
                                              std::to_string(ID+1));
        clear_file_requests(key.substr(0, key.rfind("-")), 
                                              std::to_string(ID+1));
        hits += req;
        return 0;
    }
    return -1;
}

//if return value >=0:found,  <0: forward
int32_t S_Cache::get_readcached_packet(const string& key, const uint32_t ID){
    Cachetable::iterator cit = cache_table_r.find(key);
    if(cit == cache_table_r.end()) return -1;
    LRU->update_object(LRU->objects[key]);
    //log_file_hit(_filename, _ID);
    uint32_t req = get_file_requests(key.substr(0, key.rfind("-")), 
                                              std::to_string(ID+1));
    clear_file_requests(key.substr(0, key.rfind("-")), 
                                              std::to_string(ID+1));
    hits += req;
    return 0;
}

//if return value >0:found,  <0: forward
int32_t S_Cache::get_writecached_packet(const string& key, const uint32_t ID){
    Cachetable::iterator cit = cache_table_w.find(key);
    if(cit == cache_table_w.end()) return -1;
    Pkts::iterator pit = cit->second.find(ID);
    if(pit ==  cit->second.end()) return -1;
    //log_file_hit(_filename, _ID);
    uint32_t req = get_file_requests(key.substr(0, key.rfind("-")), 
                                              std::to_string(ID+1));
    clear_file_requests(key.substr(0, key.rfind("-")), 
                                              std::to_string(ID+1));
    hits += req;
    LRU_W->update_object(LRU_W->objects[key]);
    return 0;
}

//if readcache is full , delete LRU files
inline void S_Cache::checkout_readcache(const Pkts& pkts){
    if(!enable_opt){
        while(readcache_pcks + pkts.size() >= capacity_fast_table){
                int32_t removed_packets = remove_last_file_r();
                if (removed_packets == -1) {
                    cout<< "Failed to remove packets"<<endl;
                    return;
                }
                readcache_pcks -= removed_packets;
                readcache_rmlru++;
        }
        return;
    }

    uint64_t opt_fast_table = uint64_t(capacity_fast_table*OPT_RATIO);
    while(readcache_pcks + pkts.size() >= opt_fast_table){
            int32_t removed_packets = remove_last_file_r();
            if (removed_packets == -1)
                NS_ASSERT_MSG(false, "Failed to remove packets");
            readcache_pcks -= removed_packets;
            readcache_rmlru++;
    }
}

int32_t S_Cache::get_avg_readtime(const string& key, const uint32_t ID){
    int32_t lookup_time = 0;
    uint64_t addr = 0;
    addr = CityHash64(key.c_str(), key.size());
    addr = addr%slot_num;
    map <uint32_t, Slot_Object>::iterator it = data_table.find(addr);
    //print_data_table(data_table);
    if(it == data_table.end()) return -1;
    pair<bool, Pkts> pr = it->second.find(key);
    if(!pr.first) return -1;
     
    // cal lookup_time
    lookup_time = (PKT_SIZE/WIDTH)*DRAM_OLD_ACCESS_TIME*(pr.second.size()) + \
                                      DRAM_ACCESS_TIME - DRAM_OLD_ACCESS_TIME;
    return lookup_time/pr.second.size();
}

int32_t S_Cache::get_dram_packet(const string& key, const uint32_t ID){
    int32_t lookup_time = 0;
    uint64_t addr = 0;
    int32_t pcks_num = 0;
    addr = CityHash64(key.c_str(), key.size());
    addr = addr%slot_num;
    map <uint32_t, Slot_Object>::iterator it = data_table.find(addr);
    //print_data_table(data_table);
    if(it == data_table.end()) return -1;
    pair<bool, Pkts> pr = it->second.find(key);
    if(!pr.first) return -1;
     
    checkout_readcache(pr.second);

    pair<Cachetable::iterator, bool> result = 
             cache_table_r.insert(Cachetable::value_type(key, pr.second));
    // failed to insert, key may exist in cache_table_r
    if (result.second == false){
        if(cache_table_r.find(key) != cache_table_r.end()){
            pcks_num -= cache_table_r[key].size();
            LRU->remove_object(LRU->objects[key]);
            cache_table_r[key] = pr.second;
        }
    }

    LRU_Object * _obj  = new LRU_Object(key);
    LRU->add_object(_obj);     
    pcks_num += pr.second.size();  
    readcache_pcks += pcks_num;  
    slow_memory_hit +=  pcks_num;
    // cal lookup_time
    lookup_time = (PKT_SIZE/WIDTH)*pcks_num*DRAM_OLD_ACCESS_TIME + \
                              DRAM_ACCESS_TIME - DRAM_OLD_ACCESS_TIME;

    //log_file_hit(_filename, _ID);
    uint32_t req = get_file_requests(
        key.substr(0, key.rfind("-")), 
        std::to_string(ID+1));
    clear_file_requests(
        key.substr(0, key.rfind("-")), 
        std::to_string(ID+1));
    hits += req;
    reads_for_fetchings++;
    return lookup_time;
}

pair<int64_t, int64_t> S_Cache::get_cached_packet(
                         const string& _filename,
                         const string& _ID){
    int64_t lookup_time = 0;
    uint32_t ID = atoi(_ID.c_str()) - CACHING_START_INDEX;
    requests++;
    increase_file_requests(_filename, _ID);

    string key(_filename);
    key += "-";
    key.append(std::to_string(((ID/PKT_NUM)*PKT_NUM)));
   
    //int32_t lt = get_avg_readtime(key, ID); 
    if(enable_opt){
        lookup_time = get_readcached_packet2(key, ID);
    }else{
        lookup_time = get_readcached_packet(key, ID);
    }
    if(lookup_time >=0){
        fast_memory_hit++;
        //return std::make_pair(0, LRU_ACCESS_TIME);
        return std::make_pair(0, 0);
    }

    lookup_time = get_writecached_packet(key, ID);
    if(lookup_time >=0){
        fast_memory_hit++;
        //return std::make_pair(0, LRU_ACCESS_TIME);
        return std::make_pair(0, 0);
    }

    //if not cached in sram, and checkout if stored in dram
    size_t iscache = index_bf_ptr->lookup(key.c_str()); 
    if(iscache == 0){
        miss++;
        return std::make_pair(-1, 0);
    }
    read_dram_cnt++;
    lookup_time += DRAM_ACCESS_TIME - DRAM_OLD_ACCESS_TIME + 
                      DRAM_OLD_ACCESS_TIME*FILE_NUM*LRU_ENTRY_SIZE/WIDTH;
    int64_t lt = get_dram_packet(key, ID);  // for-normal
    if(lt == -1){ //for-normal
    //if (data_test.find(key) == data_test.end()){ //for-test
        false_positive_cnt++;
        miss++;
        return std::make_pair(-1, lookup_time);
    }

    //return std::make_pair(0, lookup_time + lt); // for-normal
    return std::make_pair(0, lookup_time); //for-test
}

int32_t S_Cache::remove_last_file_w(){
    string key = LRU_W->tail->filename;
    int32_t removed_packets = get_stored_packets_w(key);
    if (removed_packets == -1)
        return -1;
    cache_table_w.erase(key);
    LRU_W->remove_object(LRU_W->tail);
//    cout<<"S_Cache removed last file "<<key<<endl;
    return removed_packets;
}

/***
 * Returns the number of the stored packets in the file _filename or 0 if filename not found
 **/
int32_t S_Cache::get_stored_packets_w(const string& _filename){
    Cachetable::iterator it = cache_table_w.find(_filename);
    if (it != cache_table_w.end()){
        return it->second.size();
    }else{
        return -1;
    }
}


pair<bool,uint32_t> S_Cache::is_last(const string &key, const uint32_t ID){
   uint32_t filesize = ID + CACHING_START_INDEX; 
   string filename = key.substr(0, key.find("-"));
   filename = filename.substr(filename.rfind('/') + 1);
   map<string, uint32_t>::iterator it = (*file_map_p).find(filename); 
   if(it == (*file_map_p).end()){
        NS_ASSERT_MSG(false, "Error. Do not find file(");
   }
   if(filesize == it->second) 
       return std::make_pair(true, it->second);
   if(filesize > it->second){ 
       cout<<" filename = "<< filename 
       <<"key = "<<key
       <<" filesize = " << filesize 
       << " can not be more than "<< it->second <<endl;
       NS_ASSERT_MSG(false, "Error.filesize can not be more than ");
   }
   return std::make_pair(false, it->second);
}

//divide into each cache due to a bug in ns3 
int32_t S_Cache::get_avg_writetime(const uint32_t ID, const uint32_t total_length){
    int32_t wt = 0;
    if(ID < (total_length/PKT_NUM)*PKT_NUM){
        wt = (PKT_NUM)*(PKT_SIZE/WIDTH)*DRAM_OLD_ACCESS_TIME + \
                      DRAM_ACCESS_TIME - DRAM_OLD_ACCESS_TIME;
        return wt/PKT_NUM;
    }else{
        uint32_t s = total_length - (ID/PKT_NUM)*PKT_NUM;
        wt = (s)*(PKT_SIZE/WIDTH)*DRAM_OLD_ACCESS_TIME + \
                      DRAM_ACCESS_TIME - DRAM_OLD_ACCESS_TIME;
        return wt/s;
            
    }
}

uint32_t S_Cache::store_packets(const string& key, 
                                const uint32_t last_id, 
                                const Pkts & pkts){
    uint32_t write_time = 0;
    uint64_t addr = 0;
    addr = CityHash64(key.c_str(), key.size());
    addr = addr%slot_num; 
    map <uint32_t, Slot_Object>::iterator dtit = data_table.find(addr);
    pair<bool, int> pr;
    if(dtit != data_table.end()) {
        pr = dtit->second.insert_packets(key, last_id, pkts);
    }else {
        Slot_Object so;
        pr = so.insert_packets(key, last_id, pkts);
        data_table.insert(map<uint32_t, Slot_Object>::value_type(addr, so));
    }
    NS_ASSERT_MSG(pr.first, "Error.Fail to insert_packets");
    index_bf_ptr->add(key.c_str());
    data_test.insert(key);  //for-test

    stored_packets += pr.second;
    total_stored_packets += pkts.size();
    
    write_time = (pkts.size())*(PKT_SIZE/WIDTH)*DRAM_OLD_ACCESS_TIME + \
                 DRAM_ACCESS_TIME - DRAM_OLD_ACCESS_TIME;
    write_for_storings++;
    return write_time;
}

inline void S_Cache::checkout_writecache(){
    if(writecache_pcks >= capacity_fast_table){
        int32_t removed_packets = remove_last_file_w();
        if (removed_packets == -1){
            NS_ASSERT_MSG(false, "Internal error. Fail to remove packets in writecache!"); 
        }        
        writecache_pcks -= removed_packets;
        writecache_rmlru++;
    }
}


// Cache packets and transfer them to dram,
// when the number is more than PKT_NUM or is last one in file.
int64_t S_Cache::add_packet(const string& key, 
                            const uint32_t ID, 
                            const uint32_t chunk_id, 
                            const char *_payload){
    pair<bool,uint32_t> islast = is_last(key, ID);
    char* data = NULL;
    checkout_writecache();
    Cachetable::iterator it = cache_table_w.find(key);
    if(it != cache_table_w.end()){
        //if the packet has exited or is out-of-order, ignore it and return 0
        if((ID-chunk_id*PKT_NUM) != it->second.size()){
            write_outoforder++;
            return 0;
        }

        it->second.insert(Pkts::value_type(ID, data));
        writecache_pcks++;
        sram_stored_packets++;
        //Up to PKT_NUM or islast is true
        if(it->second.size() >= PKT_NUM || islast.first){
            uint32_t wt = store_packets(key, ID, it->second);
            LRU_W->remove_object(LRU_W->objects[key]);
            writecache_pcks -= it->second.size();
            cache_table_w.erase(it);
            return wt;
         }else{
            LRU_W->update_object(LRU_W->objects[key]);
         }
    }else{ //is first packet
        if(ID != chunk_id*PKT_NUM){
            cout<<"Packet is not the first key="<<key
                <<" ID="<<ID<<" chunk_id*PKT_NUM="<<(chunk_id*PKT_NUM)<<endl;
            write_outoforder++;
            return 0;
        }
        Pkts pkts;
        pkts.insert(Pkts::value_type(ID, data));
        if(islast.first){
             sram_stored_packets++;
             return store_packets(key, ID, pkts);
             //return wt;
         }else{
            cache_table_w.insert(Cachetable::value_type(key, pkts));
            writecache_pcks++;
            sram_stored_packets++;
            LRU_Object * _obj  = new LRU_Object(key);
            LRU_W->add_object(_obj);        
         } 
    }  
    return 0;
    //cout<<"S_Cache stored "<<_filename<<"/"<<_ID<<endl;
    //return write_time;    
}

bool S_Cache::is_reallycached(const string &key){
    uint64_t addr = CityHash64(key.c_str(), key.size());
    addr = addr%slot_num;
    map <uint32_t, Slot_Object>::iterator it = data_table.find(addr);
    if(it != data_table.end()){
        pair<bool, Pkts> pr = it->second.find(key);
        if(pr.first) return true;
    }
    return false;
}

uint64_t S_Cache::cache_packet(const string& _filename,
                               const string& _ID,
                               const char* _payload){
    uint64_t write_time = 0;
    uint32_t ID = uint32_t(atoi(_ID.c_str()) - CACHING_START_INDEX);
    uint32_t chunk_id = ID/PKT_NUM;

    responses++;
    uint32_t req = get_file_requests(_filename, _ID);
    req = req == 1 ? req-1: req;
    hits += req;
    clear_file_requests(_filename, _ID);

    string key(_filename);
    key = key + "-";
    key.append(std::to_string(chunk_id*PKT_NUM)); 
    // if packet has existed in dram, ignore and
    // return time taked to look up tables.
    size_t iscache = index_bf_ptr->lookup(key.c_str()); 
    cache_packet_bf_lookup++;
    if(iscache){
        // ForTest
        if (data_test.find(key) == data_test.end()) {
            false_positive_cnt_w_test++;
        }
        
        write_time += DRAM_ACCESS_TIME - DRAM_OLD_ACCESS_TIME +
                      (FILE_NUM*LRU_ENTRY_SIZE/WIDTH)*DRAM_OLD_ACCESS_TIME;
        //if (data_test.find(key) != data_test.end()) return write_time;
        if(is_reallycached(key)) return write_time;
        false_positive_cnt_w++;
    }


    //If not exist in dram, store it.
    write_time += add_packet(key, ID, chunk_id, _payload); //for-normal
    //NS_LOG_INFO("S_Cache stored "<<_filename<<"/"<<_ID);
    return write_time;    
}

bf::a2_bloom_filter *S_Cache::init_bf(double fp){
    NS_ASSERT_MSG(capacity, "capacity can not be zero");
    NS_ASSERT_MSG(fp, "fp can not be zero");
    size_t ka; //The number of hash function for fp
    size_t cells; //bits, the number of cells to use 

    ka = std::floor(-std::log(1 - std::sqrt(1 - fp)) / std::log(2));
    cells = ka*(capacity/PKT_NUM)/std::log(2);

    cout<<"Init A^2  BF,"
       << "fp = " << fp
       << " ka = " << ka 
       << " cells = " << cells 
       << " size = " << cells/1024/1024 << " Mb "
       << " capacity = " << capacity
       << " capacity/PKT_NUM/2 = " << (capacity/PKT_NUM/2)<<endl;

    return new bf::a2_bloom_filter{ka, cells, capacity/PKT_NUM/2, 1, 199};
}


