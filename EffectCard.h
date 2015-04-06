#ifndef EFFECTCARD_H
#define EFFECTCARD_H
#include <list>
class Effect;
class Game;

class EffectCard
{
    public:
        /** Default constructor */
        EffectCard();
        EffectCard(std::list<Effect*> lista);
        /** Default destructor */
        virtual ~EffectCard();
        void doEffects(Game*);
    protected:
        std::list<Effect*> lista;
    private:
};

#endif // EFFECTCARD_H
