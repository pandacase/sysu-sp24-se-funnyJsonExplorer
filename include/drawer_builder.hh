
#ifndef DRAWER_BUILDER_H
#define DRAWER_BUILDER_H

#include "drawer_factory.hh"

enum StyleType {
  TreeStyle, 
  RectStyle
};

enum IconType {
  NoneIcon, 
  PokerIcon
};

class DrawerBuilder {
private:
  StyleType _style;
  IconType _icon;

public:
  void buildStyle(std::string type);

  void buildIcon(std::string type);

  std::unique_ptr<Drawer> build();

};

#endif // DRAWER_BUILDER_H