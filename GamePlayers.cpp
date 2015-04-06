#include "GamePlayers.h"
#include <thread>
using namespace std;
GamePlayers::GamePlayers ( std::list<EffectivePlayer*> lista ) :
    lista ( lista ),threads(list<thread*>())
{
}
/** Default destructor */
GamePlayers::~GamePlayers() {
    for(auto x: lista){
       x->_getRunning();

    }

}

std::list<EffectivePlayer*> GamePlayers::getTurnOrder() {}
House* GamePlayers::getHouse ( Player* ) {}
void GamePlayers::notifyStart ( Game* game ) {
    // Criar uma thread para cada jogador
    for(auto x: lista){
        auto start=[this,game,x]{x->_start(game);};
        thread* novo=new thread(start);
         novo->detach();
         threads.push_back(novo);
    }

}
void GamePlayers::updateTurnOrder() {
    lista.sort();
}
void GamePlayers::notifyGameEvent ( GameEvent e ) {
    for(auto x: lista){
        x->_addIngameEvent(e);
    }
}
void GamePlayers::notifyTurnEvent ( TurnEvent e ) {
    for(auto x: lista){
        x->_addOnTurnEvent(e);
    }

}
