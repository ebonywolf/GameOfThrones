#ifndef EFFECTIVEPLAYER_H
#define EFFECTIVEPLAYER_H
#include "Player.h"

class EffectivePlayer:public Player
{
    public:
        /** Default constructor */
        EffectivePlayer();
        EffectivePlayer(std::string name);
        /** Default destructor */
        virtual ~EffectivePlayer();
        bool operator<(Player&);
    protected:
    private:

        friend GamePlayers;


         struct PlayerSignals{
            std::mutex turnEvent;
            std::mutex gameEvent;
            std::mutex Map;
            std::mutex Houses;
        };
        PlayerSignals signals;

        void _start(Game*) ;//vai ser chamado numa thread;

		void _updateMap(Map&&);
		void _updateHouses(GameHouses&&);
		bool _getRunning();
		std::list<TurnEvent> _turnEvents;
        std::list<GameEvent> _gameEvents;

        void _addOnTurnEvent(TurnEvent e) ;
        void _addIngameEvent ( GameEvent e );
        std::string  getName() {return _name;}


        Game* _game;
        bool _running=false;
		Map _map;
		std::string _name;
};

#endif // EFFECTIVEPLAYER_H
