#include "EffectivePlayer.h"

EffectivePlayer::EffectivePlayer():EffectivePlayer("default"){}
EffectivePlayer::EffectivePlayer(std::string name):	_name ( name ),
	_gameEvents ( std::list<GameEvent>() ),
	_turnEvents ( std::list<TurnEvent>() )
{
    //ctor
}

EffectivePlayer::~EffectivePlayer()
{
    //dtor
}
bool EffectivePlayer::_getRunning() {

}
void EffectivePlayer::_start ( Game* g ) {

}
void EffectivePlayer::_addOnTurnEvent(TurnEvent e) {
    signals.turnEvent.lock();

    _turnEvents.push_back(e);

    signals.turnEvent.unlock();

}
void EffectivePlayer::_addIngameEvent ( GameEvent e ){
    signals.gameEvent.lock();

    _gameEvents.push_back(e);

    signals.gameEvent.unlock();
}
