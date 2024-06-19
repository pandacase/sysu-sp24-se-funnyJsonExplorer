

#include "drawer_builder.hh"

void 
DrawerBuilder::buildStyle(std::string type)
{
  if (type == "tree") {
    _style = StyleType::TreeStyle;
  } else if (type == "rect") {
    _style = StyleType::RectStyle;
  } else {
    throw std::runtime_error("No matched style type, tree or rect provided.");
  }
}


void 
DrawerBuilder::buildIcon(std::string type)
{
  if (type == "none") {
    _icon = IconType::NoneIcon;
  } else if (type == "poker") {
    _icon = IconType::PokerIcon;
  } else {
    throw std::runtime_error("No matched icon type, none or poker provided.");
  }
}


std::unique_ptr<Drawer> 
DrawerBuilder::build() 
{
  if (_style == StyleType::TreeStyle) {
    auto factory = new TreeDrawerFactory();
    if (_icon == IconType::NoneIcon)
      return std::move(factory->createNoneDrawer());
    else if (_icon == IconType::PokerIcon)
      return std::move(factory->createPokerDrawer());
  } else if (_style == StyleType::RectStyle) {
    auto factory = new RectDrawerFactory();
    if (_icon == IconType::NoneIcon)
      return std::move(factory->createNoneDrawer());
    else if (_icon == IconType::PokerIcon)
      return std::move(factory->createPokerDrawer());
  }
}

