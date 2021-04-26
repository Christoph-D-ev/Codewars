#include <string>
#include <algorithm>

/*
This function converts a string to a new string 
where each character in the new string is "(" if that character appears only once in the original string,
or ")" if that character appears more than once inthe original string.
Ignores capitalization when determining if a character is a duplicate.

*/

std::string duplicate_encoder(const std::string& s){
  std::unordered_map<char, int> charCount;
    
    //add 1 to every bucket denominated by the chars in the string
    for(char c : s) charCount[tolower(c)]++;

    std::string ans = "";
    //"replace" every unique  char with "("
    //and all the others with ")"
    for(char c : s) ans += (charCount[tolower(c)] > 1)? ')' : '(';

    return ans;
  
}
