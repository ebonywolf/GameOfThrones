#ifndef TERRITORY_H
#define TERRITORY_H

#include <iostream>
#include <list>
#include "Unit.h"

class HitBox;
class House;

class Territory {
	public:
		/** Default constructor */
		enum Type {
			SEA, LAND, PORT
		};
		Territory ()=default;
		Territory ( std::string name, Type type, std::list<std::string> neighbors );
		/** Default destructor */

		House* getOwner();
		std::string getName();
		Type getType();
		std::list<std::string> getNeighbors();
		std::list<std::string> getUnits();


		const std::string name;
		const Type type;
		virtual ~Territory();
	protected:
		House* Owner;
        std::list<Unit> units;
		std::list<std::string> neighbors;
	private:
};

#endif // TERRITORY_H
