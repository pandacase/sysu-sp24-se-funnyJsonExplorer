#include <string>
#include <iostream>

#include "cxxopts.hh"

#include "json_tree.hh"
#include "drawer.hh"
#include "drawer_factory.hh"
#include "drawer_builder.hh"

int main(int argc, char* argv[]) {
  try {
    cxxopts::Options options("fje", "A Funny JSON Explorer.");

    options.add_options()
      ("h,help", "Print usage")
      ("f,file", "Input json file", cxxopts::value<std::string>())
      ("s,style", "Json drawer style", 
        cxxopts::value<std::string>()->default_value("tree"))
      ("i,icon", "Json drawer icon", 
        cxxopts::value<std::string>()->default_value("none"))
      ("c,config", "Config file path", cxxopts::value<std::string>());

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
      std::cout << options.help() << std::endl;
      return 0;
    }
    if (!result.count("file")) {
      throw std::runtime_error(
        "Missing required input JSON file option (--file)");
    }

    std::string fileName = result["file"].as<std::string>();
    std::string style = result["style"].as<std::string>();
    std::string icon = result["icon"].as<std::string>();

    auto js = std::make_shared<JsonTree>();
    js->readJson(fileName);

    auto builder = std::make_unique<DrawerBuilder>();
    builder->buildStyle(style);
    builder->buildIcon(icon);

    auto drawer = builder->build();
    
    if (drawer) {
      drawer->clear();
      auto res = drawer->getOutput(js->getRoot());
      res->print();
    }

    return 0;
    
  } catch (const std::exception& e) {
    std::cerr << "Error parsing options: " << e.what() << std::endl;
    return 1;
  }
}
