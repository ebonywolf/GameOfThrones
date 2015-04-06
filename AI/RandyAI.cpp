#include "RandyAI.h"
#include <iostream>
using namespace std;
RandyAI::RandyAI()
{
	//ctor
}

RandyAI::~RandyAI()
{
	//dtor
}
void RandyAI::start() {
    std::cout<< "Starting randy" <<endl;

}
void RandyAI::onTurnEvent ( TurnEvent e ) {
    //std::cout<< e <<endl;
}
void RandyAI::ingameEvent ( GameEvent e ) {
   // std::cout<< e <<endl;
}
