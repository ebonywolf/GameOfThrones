#ifndef GAME_H
#define GAME_H
#include <list>

#include "GamePlayers.h"
#include "EffectivePlayer.h"
#include "GameMap.h"
#include "GameRules.h"
#include "GameDeck.h"
#include "GameEvent.h"
#include "Deck.h"

class Game
{
    friend GameRules;
	public:
		/** Default constructor */
		Game ( GamePlayers players, GameMap* map, GameRules* rules,GameDeck deck);
		void start();

		/** Default destructor */
		virtual ~Game();
	protected:
        int phase=0;
		GamePlayers players;
		std::list<EffectivePlayer*> turnOrder;
		GameMap* map;
		GameRules* rules;
		GameDeck decks;

		bool gameOver;

	private:

};

#endif // GAME_H
