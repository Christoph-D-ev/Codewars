std::vector < int> josephus(std::vector < int > items, int k) {
  std::vector<int> res;
  int i =(k-1);
 
  while(!items.empty()){
  //loop with modulo by treating the vector as a mathmatical modulo ring
     i=i%(items.size());
   
   //add item to the new vector and remove from old
    res.push_back(items[i]);
    items.erase(items.begin()+i);
    //advance index by given amount
    i=i+k-1;
   
    
  }
  
  return res;
  
}
