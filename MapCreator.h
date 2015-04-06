#ifndef MAPCREATOR_H
#define MAPCREATOR_H
#include <ProjGaia/Tools/Listener.h>
#include <ProjGaia/Tools/MouseEvent.h>
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <ProjGaia/Tools/Coord.h>
class MapCreator:public pg::Listener<pg::MouseEvent>
{
    public:
        //territory numb
        struct dataBlock{
            //short namesize
            std::string name="";

            //short polySize;
            std::vector<pg::Coord> poly= std::vector<pg::Coord>();

            pg::Coord center;

            //short neighborAmount
            //short namesize
            std::vector<std::string> neighbors=std::vector<std::string >();

        };
        /** Default constructor */
        MapCreator(std::string input,std::string output);
        void setCenter(pg::MouseEvent);
        void notify(pg::MouseEvent);
        void saveOutdated();

        /** Default destructor */
        virtual ~MapCreator();
    protected:
        int cont;

        std::vector<dataBlock> data;

        std::string input;
        std::string output;
    private:
        bool done=false;
        void readOutdated();
};

#endif // MAPCREATOR_H
