#include <iostream>
#include <vector>

using namespace std;
int main(){
   int x, y;
   x =2;
   y = 4;
   cout<<"x="<<x<<" y="<<y<<endl;
   swap(x, y);
   cout<<"x="<<x<<" y="<<y<<endl;
 
   vector<size_t> xx,yy;
   xx.push_back(1);
   xx.push_back(2);
   yy.push_back(4);
   yy.push_back(8);
   for(size_t i=0; i<xx.size(); i++)
       cout<<"xx i="<<i<<" value="<<xx[i]<<endl;
   for(size_t i=0; i<yy.size(); i++)
       cout<<"yy i="<<i<<" value="<<yy[i]<<endl;
   swap(xx, yy);
   for(size_t i=0; i<xx.size(); i++)
       cout<<"xx i="<<i<<" value="<<xx[i]<<endl;
   for(size_t i=0; i<yy.size(); i++)
       cout<<"yy i="<<i<<" value="<<yy[i]<<endl;
}
