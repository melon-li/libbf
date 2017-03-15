#include "Cache.h"
using namespace std;

#define PKT_NUM 8
#define QUEUE_SIZE 100
bf::a2_bloom_filter *init_bf(double fp, size_t capacity){
    size_t ka; //The number of hash function for fp
    size_t cells; //bits, the number of cells to use
    double fa = 1 - std::sqrt(1-fp);
    printf("fp= %.4f, fa = %.4f\n", fp, fa);
    ka = std::floor(-std::log(fa) / std::log(2));
    cells = 2*ka*(capacity)/std::log(2);
    std::cout<<"ka = "<<ka<<" cells = "<<cells<<std::endl;
    return new bf::a2_bloom_filter{ka, cells, capacity, 1, 199};
}

void parseFileMap(vector<pair<string, uint32_t> > &workload,
                  map<string, uint32_t> &filesMap){
    std::ifstream myfile ("./workload_globetraff");
    string file,line;
    uint32_t packets=0;
    uint64_t sum_packets=0;
    while (getline(myfile, line)) {
        file = (line.substr(0, line.find(" ")).c_str());
        packets = atoi(line.substr(line.find(" ")+1).c_str());
        workload.push_back(make_pair(file,  packets));
        sum_packets += packets;
        if (filesMap.find(file) == filesMap.end()) {
            filesMap[file] = packets;
        }
    }
    myfile.close();
    std::cout << "ParseFileMape: Num_of_files: "<<workload.size()<<" data: "<<sum_packets<<endl;
}

int main()
{
  //bf::basic_bloom_filter b(0.8, 100);
 size_t  end = 0;
 size_t cap =  1000;
 size_t cnt = 0;
 size_t c = 0;
 vector<pair<string, uint32_t> > workload;
 map<string, uint32_t> filesMap;
 list<pair<string, pair<uint32_t, uint32_t> > > curSendPkts;
 set<string> data;
 parseFileMap(workload, filesMap);
 bf::a2_bloom_filter *b;
 S_Cache sc(3579139, 4127, &filesMap, 0.001, false);
 b = init_bf(0.001, 223696);
 
    std::ifstream myfile ("./workload_globetraff_details");
    cout<<"Open workload_globetraff_details"<<endl;
    string type, key, seq, line;
    uint32_t packets=0;
    uint64_t sum_packets=0;
    while (getline(myfile, line)) {
        type = line.substr(0, line.find(" "));
        key = line.substr(line.find(" ")+1);
        seq = key.substr(key.rfind("/")+1);
        key = key.substr(0, key.rfind("/"));
        if (type == "get") {
             sc.get_cached_packet(key, seq);
             //cout<<line<<endl;
        } else if (type == "Put") {
             sc.cache_packet(key, seq, NULL);
             //cout<<line<<endl;
        }
    }
    myfile.close();

  cout<<"false_positive_cnt = " << sc.false_positive_cnt
    << "fp = " << (float(sc.false_positive_cnt)/(sc.read_dram_cnt + sc.miss - sc.false_positive_cnt))
    << " read_dram_cnt = " << sc.read_dram_cnt 
    << " miss = " << sc.miss
    << " hits = " << sc.hits
    << " slow_memory_hits = " << sc.slow_memory_hit
    << " fast_memory_hits = " << sc.fast_memory_hit << "\n"
    << " fp_w = " << (float(sc.false_positive_cnt_w)/(sc.cache_packet_bf_lookup))
    << " false_positive_cnt_w = " << sc.false_positive_cnt_w
    << " false_positive_cnt_w_test = " << sc.false_positive_cnt_w_test
    << " cache_packet_bf_lookup = " << sc.cache_packet_bf_lookup << endl;
   cout<<endl;
   cout<<endl;

  return 0;
}
