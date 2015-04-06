#ifndef UNIT_H
#define UNIT_H
#include <iostream>

class Unit
{
    public:
        /** Default constructor */
        Unit();
        Unit(int str,std::string type);
        /** Default destructor */
        virtual ~Unit();
        std::string type;
        short strength;

    protected:


    private:
};

#endif // UNIT_H
