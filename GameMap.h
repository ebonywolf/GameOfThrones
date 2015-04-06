#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "Map.h"
#include "Territory.h"
class GameMap: public Map
{
	public:
		/** Default constructor */
		GameMap ()=default;
		GameMap ( std::list<Territory> territories );
		void createStartingUnits();
		/** Default destructor */
		virtual ~GameMap();
	protected:
	private:
};

#endif // GAMEMAP_H
