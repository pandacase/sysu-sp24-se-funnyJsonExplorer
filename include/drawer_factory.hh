
#ifndef DRAWER_FACTORY_H
#define DRAWER_FACTORY_H

#include "drawer.hh"

class DrawerFactory {
public:
  virtual std::unique_ptr<Drawer> createNoneDrawer() = 0;
  virtual std::unique_ptr<Drawer> createPokerDrawer() = 0;

};


class TreeDrawerFactory : public DrawerFactory {
public:
  std::unique_ptr<Drawer> createNoneDrawer() override;
  std::unique_ptr<Drawer> createPokerDrawer() override;
};


class RectDrawerFactory : public DrawerFactory {
public:
  std::unique_ptr<Drawer> createNoneDrawer() override;
  std::unique_ptr<Drawer> createPokerDrawer() override;
};


#endif // DRAWER_FACTORY_H
