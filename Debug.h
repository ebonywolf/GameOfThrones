#ifndef DEBUG_H
#define DEBUG_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <ProjGaia/Tools/LineSeg.h>
#include <ProjGaia/Tools/Coord.h>
#include <ProjGaia/SFML/Renderer.h>

class Debug
{
	public:
		static pg::Renderer* render;
		static bool controls[10];
		/** Default constructor */
		Debug();
		/** Default destructor */
		virtual ~Debug();
		static  sf::Shape* createCircle ( pg::Coord c, sf::Color ) ;
		static sf::Shape* createLine ( pg::LineSeg line, sf::Color );
		static void addShape ( sf::Shape* );
	protected:
	private:
};

#endif // DEBUG_H
