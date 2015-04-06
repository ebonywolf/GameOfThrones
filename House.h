#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <list>
#include "Deck.h"
#include "General.h"

class Territory;
class Unit;
class House
{
	public:

//		House ( std::string name, short power, short supply, short keeps, Deck<General*>, std::list<Territory*>, std::list<Unit*> );
		short power;
		short supply;
		short keeps;

		short position_IronThrone;
		short position_KingsCourt;
		short position_Fiefdoms;

		std::string name;

		std::list<Territory*> territories;
		std::list<Unit*> units;
		bool operator< ( House& );
		virtual ~House();
	protected:
	private:
};

#endif // HOUSE_H
