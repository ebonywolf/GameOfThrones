#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <list>
#include <mutex>

#include "GameEvent.h"
#include "TurnEvent.h"
#include "Map.h"
#include "GameHouses.h"

class Game;
class GamePlayers;

class Player //classe rodando assyncrona ao restante do jogo
{
	public:
         Player ( );
        Player ( std::string name );
		virtual ~Player();
        virtual void start() = 0;
		virtual void onTurnEvent(TurnEvent e) = 0;
		virtual void ingameEvent ( GameEvent e ) = 0;


		/*

		const Map* map;

		//virtual std::list<Order> createOrders(std::list<OrderType> availableOrders);
		virtual MoveOrder createMoveOrder ( std::list<Territory*> eligibleTerritories ) {}
		virtual bool usePowerToken ( Territory* ) {}
		virtual PillageOrder createPillageOrder ( std::list<Territory*> eligibleTerritories ) {}
		//virtual Player* assistBattle(Battle,Territory*);
		// virtual std::list<draftOrder> draftUnit(std::list<Territory*> eligibleTerritories);
		//virtual General* chooseGeneral(Battle,Territory*);
		virtual short voteIronThrone() {
		}
		virtual short voteBlade() {}
		virtual short voteCrow() = 0;
		//virtual short voteWildling(WildlingCard);
		// virtual void eventCard(EventCard);

		// virtual bool useCrow_spyWildling();
		//virtual void nextWildlingCard(WildlingCard);
		//virtual bool useCrow_changeOrder();
		//virtual Order changeOrder(std::list<OrderType> availableOrders);

		//virtual bool useBlade_PlusPower(Battle);
		//virtual bool useBlade_newCard(Battle,Battlecard);

		//  virtual *Player decideDraw(Player* one, Player* two,DrawEvent);

		*/

//		short                 getPower() {  return house->power;}
	//	short                 getSupply() { return house->supply;}
	//	short                 getKeeps() {  return house->keeps;}
	//	std::string           getHouse() {  return house->name;}
		//std::list<Territory*> getTerritories() {    return house->territories;}
	//	std::list<Unit*>      getUnits() {  return house->units;}
//		Deck<General*>        getGenerals() {   return house->generals;}


	protected:
	private:

};

#endif // PLAYER_H
