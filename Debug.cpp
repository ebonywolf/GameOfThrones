#include "Debug.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <ProjGaia/Tools/LineSeg.h>
#include <ProjGaia/Tools/Coord.h>
#include <ProjGaia/Tools/Angle.h>
#include <ProjGaia/SFML/Renderer.h>
#define Width 5
using namespace pg;
using namespace sf;
Renderer* Debug::render = 0;
bool Debug::controls[10];
Debug::Debug()
{
	//ctor
}

Debug::~Debug()
{
	//dtor
}
void Debug::addShape ( Shape* s ) {
	render->debugDraw.push_back ( s );

}

Shape* Debug::createCircle ( Coord c, sf::Color color ) {
	sf::Shape *novo = new CircleShape ( Width / 2 );
	novo->setFillColor ( color );
	novo->setOrigin ( Width / 2, Width / 2 );
	novo->setPosition ( c.x, c.y );
	return novo;
}
Shape* Debug::createLine ( LineSeg line, sf::Color color ) {

	Shape* shape = new RectangleShape ( Vector2f ( line.getSpeed(), Width / 2 ) );
	shape->setFillColor ( color );
	shape->setPosition ( line.getStart().x, line.getStart().y );
	float ang = pg::Angle::radianToDegree ( ( line.getAngle() ) );
	shape->setRotation ( ang );
	return shape;



}
