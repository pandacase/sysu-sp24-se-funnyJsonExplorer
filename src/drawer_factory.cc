
#include "drawer_factory.hh"


//////////////////////////////////////////////////////////////////
// TreeDrawerFactory
//////////////////////////////////////////////////////////////////



std::unique_ptr<Drawer>
TreeDrawerFactory::createNoneDrawer()
{
  auto newDrawer = std::make_unique<TreeDrawer>();
  
  newDrawer->branch       = "├─";
  newDrawer->vertical     = "│ ";
  newDrawer->branchEnd    = "└─";
  newDrawer->verticalEnd  = "  ";

  newDrawer->leafIcon      = " ";
  newDrawer->containerIcon = " ";

  return std::move(newDrawer);
}

std::unique_ptr<Drawer>
TreeDrawerFactory::createPokerDrawer()
{
  auto newDrawer = std::make_unique<TreeDrawer>();
  
  newDrawer->branch       = "├─";
  newDrawer->vertical     = "│ ";
  newDrawer->branchEnd    = "└─";
  newDrawer->verticalEnd  = "  ";

  newDrawer->leafIcon      = "♤";
  newDrawer->containerIcon = "♢";

  return std::move(newDrawer);
}



//////////////////////////////////////////////////////////////////
// RectDrawerFactory
//////////////////////////////////////////////////////////////////


std::unique_ptr<Drawer>
RectDrawerFactory::createNoneDrawer()
{
  auto newDrawer = std::make_unique<RectDrawer>();
  
  newDrawer->branch       = "├─";
  newDrawer->vertical     = "│ ";
  newDrawer->branchEnd    = "├─";
  newDrawer->verticalEnd  = "│ ";

  newDrawer->leafIcon      = " ";
  newDrawer->containerIcon = " ";

  return std::move(newDrawer);
}

std::unique_ptr<Drawer>
RectDrawerFactory::createPokerDrawer()
{
  auto newDrawer = std::make_unique<RectDrawer>();
  
  newDrawer->branch       = "├─";
  newDrawer->vertical     = "│ ";
  newDrawer->branchEnd    = "├─";
  newDrawer->verticalEnd  = "│ ";

  newDrawer->leafIcon      = "♤";
  newDrawer->containerIcon = "♢";

  return std::move(newDrawer);
}

