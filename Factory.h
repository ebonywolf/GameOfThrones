#ifndef FACTORY_H
#define FACTORY_H

class Game;
class Factory
{
    public:
        /** Default constructor */
        Factory();
        static Game* CreateTestGame();



        /** Default destructor */
        virtual ~Factory();
    protected:
    private:
};

#endif // FACTORY_H
