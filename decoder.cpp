struct Decoder {
  static std::string decode (const std::string& p_what) {  
    std::cout << (Encoder::encode ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")) << "\n" ;
    std::cout << (Encoder::encode ("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")) << "\n" ;  
    std::cout << (Encoder::encode ("!@#$%^&*()_+-")) << "\n" ;
    std::string a, b, c;
    for (const auto& w : std::string("abcdefghijklmnopqrstuvwxyz")) {
      a += Encoder::encode (std::string(  "") + w)[0];
      b += Encoder::encode (std::string( "_") + w)[1];
      c += Encoder::encode (std::string("__") + w)[2];
    }
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";     
  
    //i noticed that the encoding was somekind of rolling
    // so just roll back to the original 
    std::string what =p_what;
    for(int i=0;i<65;i++){
      what = Encoder::encode(what);
      
    }

    return what;
  }
};
