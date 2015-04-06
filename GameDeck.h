#ifndef GAMEDECK_H
#define GAMEDECK_H
#include <ProjGaia/Tools/Observer.h>
#include "EffectCard.h"
#include <list>
#include "GameEvent.h"
#include "Deck.h"
class Game;
class GameDeck:pg::Observer<GameEvent>
{
    public:
        /** Default constructor */
        GameDeck();
        GameDeck(std::list< Deck<EffectCard*> > lista);
        void scrambleDecks();
        void drawCards(Game*);

        /** Default destructor */
        virtual ~GameDeck();
    protected:
    std::list<Deck<EffectCard*>> lista;
    private:
};

#endif // GAMEDECK_H
