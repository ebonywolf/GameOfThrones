#ifndef PLAYERS_H
#define PLAYERS_H
#include <list>
#include "GameEvent.h"
#include "House.h"
#include "EffectivePlayer.h"
#include "TurnEvent.h"
namespace std {class thread;
}
class Game;
class GamePlayers
{
	public:
		/** Default constructor */
		GamePlayers(std::list<EffectivePlayer*> lista);
		/** Default destructor */
		virtual ~GamePlayers();

		std::list<EffectivePlayer*> getTurnOrder();
		House* getHouse ( Player* );
		void notifyStart(Game*);//create Multiple threads

		void updateTurnOrder();
		void notifyGameEvent(GameEvent e);
		void notifyTurnEvent(TurnEvent e);

	protected:
        std::list<EffectivePlayer*> lista;
        std::list<std::thread*> threads;
	private:
};

#endif // PLAYERS_H
