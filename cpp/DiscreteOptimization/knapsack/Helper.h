// ----------------------- Helper Functions ------------------------ //

// Calculate the weighted sum for given configuration (1 for selected item) and weights 
uint32_t calcLinearComb(std::vector<uint8_t>& conf, std::vector<uint32_t>& W){
  //for (auto it: conf){
  //  std::cout << " " << std::to_string(it);
  //}
  auto w = std::inner_product(conf.begin(), conf.end(), W.begin(), 0);
  //std::cout << "-> " << std::to_string(w) << std::endl;
  return w;
}

void testLinearComb(){
  int maxW = 0;
  std::vector<uint8_t> a{0,1};
  std::vector<uint32_t> b{12,10};

  //pW = std::make_shared<std::vector<uint32_t>>(b);
  //conf = std::make_shared<std::vector<uint8_t>>(a);

  std::string str = std::to_string(calcLinearComb(a,b));
  std::cout << str;
}


