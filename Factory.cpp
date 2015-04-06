#include "Factory.h"

#include <iostream>
#include "AI/RandyAi.h"
#include "GamePlayers.h"
#include "Territory.h"
#include "GameMap.h"
#include "GameRules.h"
#include "EffectCard.h"
#include "Deck.h"
#include "GameDeck.h"
#include "Game.h"

Factory::Factory()
{
    //ctor
}

Factory::~Factory()
{
    //dtor
}


Game* Factory::CreateTestGame(){
      std::list<EffectivePlayer*> plist=std::list<EffectivePlayer*>();
    plist.push_back(new RandyAI());

    GamePlayers gp(plist);

    Territory brasil("brasil",Territory::LAND,{"argentina"});
    Territory argentina("argentina",Territory::LAND,{"brasil"});
    std::list<Territory> tlist={brasil,argentina};

    GameMap* gm=new GameMap(tlist);

    GameRules* gr=new GameRules();

    Deck<EffectCard*> deck;

    GameDeck gd({deck});

    Game* novo= new Game(gp, gm, gr,gd);
    return novo;




}
