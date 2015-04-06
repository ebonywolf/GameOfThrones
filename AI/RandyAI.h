#ifndef RANDYAI_H
#define RANDYAI_H
#include "../EffectivePlayer.h"

class RandyAI:public EffectivePlayer
{
    public:
        /** Default constructor */
        RandyAI();
        virtual void start() ;
		virtual void onTurnEvent(TurnEvent e) ;
		virtual void ingameEvent ( GameEvent e ) ;
        /** Default destructor */
        virtual ~RandyAI();
    protected:
    private:
};

#endif // RANDYAI_H
