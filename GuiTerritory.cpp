#include "GuiTerritory.h"



GuiTerritory::GuiTerritory( std::string name, Type type, std::list<std::string> neighbors,pg::Sprite* sprite )
:Territory(name,type,neighbors),sprite(sprite)
{

}


GuiTerritory::~GuiTerritory()
{
    //dtor
}
pg::Sprite* GuiTerritory::getSprite(){
  return sprite;
}
