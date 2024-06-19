#ifndef JSON_TREE_H
#define JSON_TREE_H

#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include <stdexcept>

#include "json.hh"


//! @brief abstract class : json node
//! 
class JsonNode {
protected:
  const std::string _key;
  const std::shared_ptr<JsonNode> _parent;
  const int _level;
  const bool _is_leaf;

public:
  JsonNode(std::string key, std::shared_ptr<JsonNode> parent, int level, bool flag)
   : _key(key), _parent(parent), _level(level), _is_leaf(flag) { }

  std::string getKey() { return _key; }
  std::shared_ptr<JsonNode> getParent() { return _parent; }
  int getLevel() { return _level; }
  bool isLeaf() { return _is_leaf; }
  virtual std::vector<std::shared_ptr<JsonNode>> getChildren() = 0;
  virtual std::string getContent() = 0;
};


//! @brief concrete class : non-leaf node
//! 
class JsonContainer : public JsonNode {
private:
  std::vector<std::shared_ptr<JsonNode>> _children;

public:
  JsonContainer(std::string key, std::shared_ptr<JsonNode> parent, int level)
   : JsonNode(key, parent, level, false) { };

  void addChild(std::shared_ptr<JsonNode> newChild);
  std::vector<std::shared_ptr<JsonNode>> getChildren() override { return _children; }
  std::string getContent() override { return getKey(); }
};


//! @brief concrete class : leaf node
//! 
class JsonLeaf : public JsonNode {
private:
  std::string _value;

public:
  JsonLeaf(std::string key, std::shared_ptr<JsonNode> parent, int level)
   : JsonNode(key, parent, level, true) { };

  void setValue(std::string value) { _value = value; }
  std::string getValue() { return _value; }
  std::vector<std::shared_ptr<JsonNode>> getChildren() override { return {}; }
  std::string getContent() override { return getKey() + ": " + getValue(); }
};


//! @brief store the whole json tree
//! 
class JsonTree {
private:
  std::shared_ptr<JsonContainer> _root;

  void parseJson(nlohmann::json& subJson, std::shared_ptr<JsonContainer> parent);

public:
  void readJson(const std::string filePath);
  std::shared_ptr<JsonContainer> getRoot() { return _root; }
};


#endif // JSON_TREE_H