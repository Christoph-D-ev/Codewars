#include <math.h>
class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b){
    
    std::string str;
   //return string as concat of all parts
   str +=con(r)+con(g)+con(b);
    
    return str;
  }
  
  static std::string con(int i){
    //the HEX-"Alphabet" for quick and easy conversion
    char conv [16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
   
    //only consider valid numbers
    if(i>0&&i<255){
      std::string str;
      float num, fract ,intpart;
      
      //get integer and decimal parts of the division
      num = i;
      num = num/16;
      fract = modf(num,&intpart);
      
      //add corresponding HEX-symbol to the string
      str += conv[(int)intpart];
      str += conv[(int)(fract*16)];
     
      return str;
    }
    //ignore invalid numbers 
    //default to largest possible
    if(i>=255){
      
      return "FF";
    }
    //if all else fails return 0
    return "00";
  }
};
