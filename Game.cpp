#include "Game.h"
#include <thread>
Game::Game ( GamePlayers players, GameMap* map, GameRules* rules,GameDeck deck):
players(players),map(map),rules(rules),decks(deck)
{


}




Game::~Game()
{
	//dtor
}
void Game::start() {

	turnOrder = players.getTurnOrder();
	//players.notifyStart(this);
    phase=0;
  //  decks.scrambleDecks();
    gameOver=false;

	while(!gameOver){
	    /**Phase 1*/
	    phase=1;
//	    decks.drawCards(this);

	    /**Phase 2*/
	    phase=2;
	  //  players.notifyGameEvent(GameEvent::PLACE_ORDERS);





        //if(rules.checkVictoryCondition(this)!= 0)
	}








}
