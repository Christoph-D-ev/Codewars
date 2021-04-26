#include <vector>

int findOdd(const std::vector<int>& numbers){
    std::unordered_map<int,int> intCount;
    // add 1 to every bucket demominated by the ints contained in numbers
    for(int i: numbers) intCount[i]++;
  
    //loop over all "buckets" in the map and stop if we encounter one with an odd content
    for(int i :numbers){
      if(intCount[i]%2==1){
        return i;
      }
    }

}
