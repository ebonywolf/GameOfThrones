#ifndef POLYGONCREATOR_H
#define POLYGONCREATOR_H

#include <iostream>
#include <ProjGaia/Tools/Listener.h>
#include <ProjGaia/Tools/MouseEvent.h>

#include <list>
#include "ProjGaia/Tools/LineSeg.h"
#include <fstream>
#include "ProjGaia/Tools/Polygon.h"

#include <ProjGaia/SFML/DrawableLine.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#define RADIUS 2
class ColoredShape;

namespace pg{
class Renderer;
}
class PolygonCreator : public pg::Listener<pg::MouseEvent> {
	public:
		struct territoryDat {
			std::string name;
			pg::Polygon poly;
			pg::Coord center;
			std::list<std::string> neighbors;

		};
		PolygonCreator ( pg::Renderer* );
		void notify ( pg::MouseEvent );
		virtual ~PolygonCreator();

		[[deprecated("Need to update file structure")]]
		void createPolygons ( std::string file, std::string output );


	protected:



		std::vector<std::string> nomes;


		std::list<pg::Coord> pontos;
		std::list<pg::ColoredShape*> shapes;
		//std::list<pg::LineSeg> vetores;
		std::list<pg::DrawableLine*> lines;
		std::string output;


		pg::Coord last = pg::Coord ( 0, 0 );
		pg::Renderer* window;
	private:

	    void drawBorders(pg::MouseEvent event);
		bool working = false;
		void savePolygon();
		pg::Coord verificarPonto ( pg::Coord );
		void nextPolygon();
		int cont;


};

#endif // POLYGONCREATOR_H
