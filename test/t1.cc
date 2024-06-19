#include <iostream>
#include <fstream>

#include "../third-party/json.hh"

using json = nlohmann::json;


int main() {
  std::ifstream file("./example.json");
  if (!file.is_open()) {
    std::cerr << "CAN NOT OPEN" << std::endl;
  }
  json js;
  file >> js;

  js = js["oranges"]["mandarin"];
  
  for (auto it = js.begin(); it != js.end(); ++it) {
    if (it->is_object()) {

    } else if (it->is_array()) {

    } else if (it->is_string()) {
      auto key = it.key();
      auto value = it->dump();
      std::cout << value << std::endl;
    } else if (it->is_number()) {
      auto value = it->dump();
      std::cout << value << std::endl;
    }
  }
}