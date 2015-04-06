#include "GuiMap.h"
using namespace pg;

GuiMap::GuiMap(pg::PainterType* painter,std::string mapFile,pg::Sprite** mapSprite )
:painter(painter),mapSprite(mapSprite)
{
    painter->addDrawable(this);
    loadFile(mapFile);
}

GuiMap::~GuiMap()
{

}
Sprite* GuiMap::getSprite(){
    return mapSprite[0];
}
Territory GuiMap::selectTerritory(pg::Coord c){

    //TODO :SelectTerritory

}
void GuiMap::loadFile(std::string){


}
