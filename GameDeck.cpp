#include "GameDeck.h"

GameDeck::GameDeck()
{
    //ctor
}
GameDeck::GameDeck(std::list< Deck<EffectCard*> > list):
lista(list)
{

}
GameDeck::~GameDeck()
{
    //dtor
}
