#ifndef MAP_H
#define MAP_H
#include "Territory.h"
#include <list>
#include <iostream>
class Map
{
	public:
		/** Default constructor */
		Map ( )=default;
		Map ( std::list<Territory> territories );
		/** Default destructor */
		Territory getTerritory ( std::string s );
		std::list<Territory> getAllTerritories();
		virtual ~Map();
	protected:
	private:
};

#endif // MAP_H
