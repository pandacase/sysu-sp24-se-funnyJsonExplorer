
#ifndef DRAWER_H
#define DRAWER_H

#include <iostream>
#include <vector>
#include <string>

#include "json_tree.hh"
#include "buffer.hh"





class Drawer {
  friend class DrawerFactory;
  friend class TreeDrawerFactory;
  friend class RectDrawerFactory;

protected:
  std::shared_ptr<StringBuffer> _str_buffer 
    = std::make_shared<StringBuffer>();

  //! @style {
  std::string branch;
  std::string vertical;
  std::string branchEnd;
  std::string verticalEnd;
  //! @ }

  //! @icon {
  std::string leafIcon;
  std::string containerIcon;
  //! @ }


  //! @StagedDrawer {
  virtual void drawNode(
    const std::shared_ptr<JsonNode>& jsonNode,
    const std::string& selfCont,
    const std::string& childCont) = 0;
  void drawIcon();
  virtual void drawFmt() = 0 ;
  //! @ }

public:
  std::shared_ptr<StringBuffer> getOutput(
    const std::shared_ptr<JsonNode>& rootNode);
  
  void clear() { _str_buffer->clear(); }
};


class TreeDrawer : public Drawer {
protected:
  void drawNode(
    const std::shared_ptr<JsonNode>& jsonNode,
    const std::string& selfCont,
    const std::string& childCont) override;
  void drawFmt() override;
};


class RectDrawer : public Drawer {
protected:
  void drawNode(
    const std::shared_ptr<JsonNode>& jsonNode,
    const std::string& selfCont,
    const std::string& childCont) override;
  void drawFmt() override;
};


#endif // DRAWER_H