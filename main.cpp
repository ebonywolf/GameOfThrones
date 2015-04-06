
#include "Factory.h"
#include "Game.h"
#include "MapCreator.h"
#include <ProjGaia/Graphics/Camera.h>
#include <ProjGaia/Tools/Coord.h>
#include <ProjGaia/SFML/Renderer.h>
#include <ProjGaia/SFML/TexturedSprite.h>
#include <ProjGaia/SFML/StaticImage.h>
#include <SFML/Graphics/Texture.hpp>
#include <ProjGaia/Tools/CameraMouseControl.h>
#include <ProjGaia/Tools/KeyBoardEvent.h>
#include <ProjGaia/Tools/Listener.h>

#include "BasicRenderer.h"
using namespace std;
using namespace pg;
class A: pg::Listener<pg::KeyBoardEvent>
{
	public:
		CameraMouseControl* cam1;
		CameraMouseControl* cam2;
		int a = 1;
		Renderer* ren;

		A()
		{
			Camera* novocam = new Camera();
			pg::Coord c ( 1200, 800 );
			sf::Texture* text = new sf::Texture();
			text->loadFromFile ( "img/got.jpg" );

			TexturedSprite* foto = new TexturedSprite ( text, pg::Coord() );
			StaticImage mapa ( foto );


			ren = new Renderer ( "Test", novocam, c, c );
			MapCreator mc ( "mapas/mapa1.map", "mapas/mapaTerra.map1" );
			ren->MouseReader::addListener ( &mc );

			cam1 = new CameraMouseControl ( novocam, ren, 5 );
			cam2 = new CameraMouseControl ( novocam, ren, 5 );
			cam2->BORDER = .90;
			cam1->acceleration = true;

			ren->MouseReader::addListener ( cam1 );
			ren->MouseReader::addListener ( cam2 );
			ren->KeyBoardReader::addListener ( this );

			ren->addDrawable ( &mapa );
			ren->begin();

		}


		void notify ( KeyBoardEvent e )
		{


		}



};



int main()
{


}
