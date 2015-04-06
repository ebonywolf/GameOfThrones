#ifndef GUIMAP_H
#define GUIMAP_H
#include "GameMap.h"
#include "GuiTerritory.h"
#include <ProjGaia/Graphics/PainterType.h>
#include <ProjGaia/Graphics/DrawableType.h>
#include <ProjGaia/Tools/Coord.h>
#include <iostream>
#include <list>
class GuiMap:public GameMap,public DrawableType
{
    public:
        GuiMap(pg::PainterType* painter,std::string mapFile,pg::Sprite** mapSprite  );
        virtual ~GuiMap();
        Territory selectTerritory(pg::Coord);
        pg::Sprite* getSprite();
    protected:
        pg::Sprite** mapSprite; /**< 0= map, 1=land, 2=sea, 3=port */
        virtual void loadFile(std::string);
        pg::PainterType* painter;
        std::list<GuiTerritory> sprites;
    private:

};

#endif // GUIMAP_H
