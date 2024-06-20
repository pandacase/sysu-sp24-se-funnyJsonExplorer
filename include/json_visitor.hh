#ifndef JSON_VISITOR_H
#define JSON_VISITOR_H

#include <iostream>

#include "json_tree.hh"


class JsonVisitor {
public:
    virtual void visit(JsonContainer& container) = 0;
    virtual void visit(JsonLeaf& leaf) = 0;
    virtual ~JsonVisitor() {}
};



class PrintVisitor : public JsonVisitor {
public:
    void visit(JsonContainer& container) override {
        std::cout << "Container: " << container.getKey() << std::endl;
    }

    void visit(JsonLeaf& leaf) override {
        std::cout << "Leaf: " << leaf.getContent() << std::endl;
    }
};

#endif // JSON_VISITOR_H