#ifndef JSON_ITERATOR_H
#define JSON_ITERATOR_H

#include <stack>

#include "json_tree.hh"

class JsonIterator {
public:
    virtual std::shared_ptr<JsonNode> next() = 0;
    virtual bool hasNext() = 0;
    virtual ~JsonIterator() {}
};


class DfsJsonIterator : public JsonIterator {
private:
    std::stack<std::shared_ptr<JsonNode>> _stack;

public:
    DfsJsonIterator(std::shared_ptr<JsonNode> root) {
        if (root) _stack.push(root);
    }

    std::shared_ptr<JsonNode> next() override {
        if (!hasNext()) throw std::out_of_range("No more elements");

        auto node = _stack.top();
        _stack.pop();

        auto children = node->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            _stack.push(*it);
        }

        return node;
    }

    bool hasNext() override {
        return !_stack.empty();
    }
};

#endif // JSON_ITERATOR_H