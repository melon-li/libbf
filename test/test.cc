#include <iostream>
#include <bf.h>

bf::a2_bloom_filter *init_bf(double fp, size_t capacity){
    size_t ka; //The number of hash function for fp
    size_t cells; //bits, the number of cells to use
    double fa = 1 - std::sqrt(1-fp);
    printf("fa = %.4f\n", fa);
    ka = std::floor(-std::log(fa) / std::log(2));
    cells = 2*ka*(capacity)*std::log(2);
    std::cout<<"ka = "<<ka<<" cells = "<<cells<<std::endl;
    return new bf::a2_bloom_filter{ka, cells, capacity, 1, 199};
}


int main()
{
  //bf::basic_bloom_filter b(0.8, 100);
 size_t  end = 15;
 size_t cap = 4;
 size_t cnt = 0;
 size_t c = 0;
 bf::a2_bloom_filter *b;
 b = init_bf(0.01, cap);
  // Add two elements.
  for(size_t i=0; i<end; i++){
     std::cout<<"i="<<i<<std::endl;
     b->add(i);
   /*  for(size_t j=0; j<(i+1); j++){
         if(b->lookup(j) == 1 ) cnt++;
     }*/
     /*if(b->lookup(i+end) == 1){
         //std::cout<<"i="<<i<<" Bloom Filter False Positive"<<std::endl;
         cnt++;
     }*/
  }
//  printf("fp=%.4f\n", float(cnt)/float(end));
  printf("cnt=%d\n", cnt);
  return 0;
}
