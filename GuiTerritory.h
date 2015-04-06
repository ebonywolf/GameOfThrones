#ifndef GUITERRITORY_H
#define GUITERRITORY_H

#include "Territory.h"
#include <ProjGaia/Graphics/DrawableType.h>
#include <iostream>
class GuiTerritory:public Territory,public DrawableType
{
    public:
        /** Default constructor */
        GuiTerritory()=default;
        GuiTerritory ( std::string name, Type type, std::list<std::string> neighbors,pg::Sprite* sprite );
        pg::Sprite* getSprite();
        /** Default destructor */
        virtual ~GuiTerritory();
    protected:
        pg::Sprite* sprite;
    private:
};

#endif // GUITERRITORY_H
