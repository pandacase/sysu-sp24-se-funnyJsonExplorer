
#include "json.hh"

#include "json_tree.hh"



void
JsonContainer::addChild(std::shared_ptr<JsonNode> newChild)
{
  _children.push_back(newChild);
}


/////////////////////////////////////////////////

void
JsonTree::parseJson(
  nlohmann::json& subJson, 
  std::shared_ptr<JsonContainer> parent)
{
  for (auto it = subJson.begin(); it != subJson.end(); ++it) {
    if (it->is_object()) {
      auto container = std::make_shared<JsonContainer>(
        it.key(), parent, parent->getLevel() + 1);
      parent->addChild(container);
      parseJson(it.value(), container);
    } else {
      auto  leaf = std::make_shared<JsonLeaf>(
        it.key(), parent, parent->getLevel() + 1);
      
      auto valueStr = it->dump();
      if (it->is_string()) {
        // remove the "" around the string value
        valueStr = valueStr.substr(1, valueStr.length() - 2);
      } else if (it->is_null()) {
        valueStr = "";
      }

      leaf->setValue(valueStr);
      parent->addChild(leaf);
    }
  }
}


void 
JsonTree::readJson(const std::string filePath) 
{
  std::ifstream fileStream(filePath);
  if (!fileStream.is_open()) {
    std::runtime_error("Can not open file: " + filePath);
  }

  nlohmann::json json;
  fileStream >> json;
  fileStream.close();

  _root = std::make_shared<JsonContainer>("root", nullptr, 0);
  parseJson(json, _root);
}