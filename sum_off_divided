#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

class SumOfDivided
{
public:

/*
Given an array of positive or negative integers

I= [i1,..,in]

you have to produce a sorted array P of the form

[ [p, sum of all ij of I for which p is a prime factor (p positive) of ij] ...]

P will be sorted by increasing order of the prime numbers. The final result has to be given as a string



*/


    static std::string sumOfDivided(std::vector<int> &lst){
      //set to keep all discovered primes unique and in order
      std::map<int,int> sums;
      //copy so we can modify  
      std::vector<int> mod_list = lst; 
      
     
      //get all numbers divisible by 2 
      //and divide all these as much as we can
      for(int i =0;i<lst.size();i++){
        //is divisible by 2
        if(lst[i]%2 == 0){
          sums[2] = sums[2] + lst[i];
          
          //divide the number by 2 as often as we can
          while(mod_list[i]%2==0){
             mod_list[i]=mod_list[i]/2;
           }
         
          
        }
      }
      

      
     
     for(int i=0;i<lst.size();i++){
       
       for(int prime=3;prime<=abs(lst[i]);prime=prime+2){
         if(mod_list[i]%prime==0){
           
           sums[prime]=sums[prime]+lst[i];
           
           while(mod_list[i]%prime==0){
             mod_list[i]=mod_list[i]/prime;
           }
         }
       }
     }
    for(int i=0;i<lst.size();i++){
      if(mod_list[i]>2){
        sums[mod_list[i]]=sums[mod_list[i]]+lst[i];
      }
    }
      std::string return_val = "";
     for(std::map<int,int>::iterator it=sums.begin();it!=sums.end();it++){
       return_val += std::string("(");
       return_val += std::to_string(it->first);
       return_val += std::string(" ");
       return_val += std::to_string(it->second); 
       return_val += std::string(")")  ;
       
     }
      
        return return_val;
    }
};
