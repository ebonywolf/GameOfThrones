
#include "PolygonCreator.h"
#include <ProjGaia/SFML/Renderer.h>
#include <math.h>
#include <ProjGaia/SFML/ColoredShape.h>
#include <ProjGaia/Tools/Coord.h>
#include <SFML/Graphics/ConvexShape.hpp>
#include <ProjGaia/SFML/ColoredShape.h>

#include <fstream>
using namespace sf;
using namespace pg;
using namespace std;
#define string std::string

PolygonCreator::PolygonCreator ( Renderer* window )
{
	this->window = window;
//    window->addMouseListener ( this );
}

PolygonCreator::~PolygonCreator()
{

}

void PolygonCreator::createPolygons ( string filename, string output ) {
	this->output = output;
	ifstream file ( filename );
	if ( !file.is_open() ) {
		std::cout << "erro em abrir " << filename << endl;
		return ;
	}
	string s;
	nomes = std::vector<string>();
	while ( getline ( file, s ) ) {
		nomes.push_back ( s );



	}
	file.close();

	ifstream input ( "mapas.sav", ios::binary );
	if ( input.is_open() ) {
		int a = 3;
		input.read ( ( char* ) &a, sizeof ( int ) );
		std::cout << a << endl;
		std::cout << "continuing at " << nomes[a] << endl;
		cont = a;

	} else {
		std::cout << "no previous save\n" << nomes[0] << endl;
		cont = 0;
	}
	input.close();
	working = true;

}
Shape* createCircle ( Coord c, sf::Color color = sf::Color::Blue ) {
	sf::Shape *novo = new CircleShape ( RADIUS );
	novo->setFillColor ( color );
	novo->setOrigin ( RADIUS, RADIUS );
	novo->setPosition ( c.x, c.y );
	return novo;
}

ConvexShape* createShape ( pg::Polygon polygon ) {
	ConvexShape* shape;

	std::list<LineSeg> lines = polygon.getLines();
	int points = lines.size();
	shape = new sf::ConvexShape ( points );
	int i = 0;
for ( auto line: lines ) {
		sf::Vector2<float> vector = sf::Vector2<float> ( line.getStart().x, line.getStart().y );
		shape->setPoint ( i, vector );
		i++;
	}
	shape->setFillColor ( sf::Color ( 0, 255, 255 ) );
	return shape;
}


void PolygonCreator::notify ( MouseEvent event ) {


}
void PolygonCreator::drawBorders(MouseEvent event){
if ( !working ) return;
	// MouseEvent::
	if ( event.click != event.LEFT_UP ) return;
	pg::Coord c = event.coord;

	if ( last.modulo() == 0 ) {
		last = c;
		pontos.push_back ( last );

		Shape* circle = createCircle ( c );
		pg::ColoredShape* novoShape = new pg::ColoredShape ( circle );

		shapes.push_back ( novoShape );

		window->addDrawable ( novoShape );

		return;
	}
	Coord temp = verificarPonto ( c );
	if ( temp.modulo() == 0 ) {
		pg::LineSeg v;
		Coord A = last;
		last = c;
		v = pg::LineSeg ( A, c );
		pontos.push_back ( last );


		sf::Shape* pointB = createCircle ( c );
		pg::ColoredShape* novoShape = new pg::ColoredShape ( pointB );
		shapes.push_back ( novoShape );

		window->addDrawable ( novoShape );


		DrawableLine* dLine = new DrawableLine ( &v, Color::Green );
		window->addDrawable ( dLine );
		lines.push_back ( dLine );


	} else {
		/*
		shapes.push_back ( lineAB );
		window->addDrawable ( lineAB );
		*/
		pg::LineSeg v ( last, temp );

		DrawableLine* dLine = new DrawableLine ( &v, Color::Green );
		window->addDrawable ( dLine );
		lines.push_back ( dLine );

		last = temp;

		this->savePolygon();
		this->nextPolygon();
	}

}

void PolygonCreator::nextPolygon() {
	cont++;
	if ( cont >= nomes.size() ) {
		working = false;
		std::cout << "done" << endl;
	}
	pontos.clear();
for ( auto x: shapes ) {
		this->window->removeDrawable ( x );
		delete ( x );
	}
	shapes.clear();
for ( auto x: lines ) {
		this->window->removeDrawable ( x );
		delete ( x );
	}
	lines.clear();

	ofstream file ( "mapas.sav", ios::binary );
	if ( file.is_open() ) {
		file.write ( ( char* ) &cont, sizeof ( char ) );


	} else {
		std::cout << "erro em salvar progresso" << endl;
	}
	if ( !working ) return;
	std::cout << "next " << nomes[cont] << endl;
	last = Coord();


}





void PolygonCreator::savePolygon() {
	ofstream file ( output, ios::binary | ios::app );
	/**
	Data Block
	int nameSize
	string chars * namesize
	int coord amount
	float x,float y * amount
	*/
	if ( file.is_open() ) {
		string name = this->nomes[cont];
		std::cout << name << endl;
		int namesize = name.size();
		std::cout << namesize << endl;

		int coordamount = pontos.size();
		file.write ( ( char* ) &namesize, sizeof ( int ) );
		for ( int i = 0; i < namesize; i++ ) {
			char a = name[i];
			file.write ( &a, sizeof ( char ) );

		}
		file.write ( ( char* ) &coordamount, sizeof ( int ) );
for ( Coord a: pontos ) {
			float x = ( a.x );
			float y = ( a.y );
			file.write ( ( char* ) &x, sizeof ( float ) );
			file.write ( ( char* ) &y, sizeof ( float ) );
		}

		file.close();



	} else {
		std::cout << "erro ao salvar poligono" << endl;
		return;
	}



}





Coord PolygonCreator::verificarPonto ( Coord b ) {

	float raio = RADIUS * 2;
for ( Coord  a: pontos ) {
		float dist = a.distance ( b );
		if ( dist <= raio ) return a;
	}
	return Coord ( 0, 0 );

}
