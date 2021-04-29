#include <math.h>
class Magnets
{

  
public:
    static double doubles(int maxk, int maxn){
      double sum=0.0;
      
      for(int j=1;j<=maxk;j++){
       
        for(int i=1;i<=maxn;i++){
          sum += 1.0 / ( j * pow((i+1),2*j) );
        }
       
      }
      std::cout<<"input: ("<<maxk<<","<<maxn<<")"<<"sum: "<<sum<<std::endl;
      return sum;
    }
};
