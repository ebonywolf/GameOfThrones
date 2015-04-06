#include "BasicRenderer.h"
#include <windows.h>

using namespace sf;
using namespace pg;
BasicRenderer::BasicRenderer ( std::string name , int width, int height ) :
	dimX ( width ), dimY ( height ),name(name)
{
	camera = new pg::Camera();

	for ( int i = 0; i < 3; i++ ) {
		sprites[i] = std::list<Drawable*>();

	}

}

BasicRenderer::~BasicRenderer()
{
	delete ( window );
	delete ( camera );
}
 void BasicRenderer::beginAssync(){
     auto func=[this](){this->begin();};
     assync=new std::thread(func);
     assync->detach();

 }
void BasicRenderer::begin(){
    ContextSettings contextSettings;
	contextSettings.depthBits = 32;
	window = new RenderWindow ( VideoMode ( dimX, dimY ), name, Style::Default, contextSettings );


    window->setActive();
	glClearDepth ( 0xff );
	glClearColor ( 0xff, 0xff, 0xff, 0xff );

	sf::Clock clock= sf::Clock();


	while ( window->isOpen() ) {
		Event event;
		while ( window->pollEvent ( event ) ) {
			if ( event.type == Event::Closed )
				window->close();
			createMouseEvent ( event );
			createKeyBoardEvent ( event );
			if ( event.type == Event::Resized ) {
			}
		}

		window->clear ( Color ( 0x00, 0x00, 0x00, 0x00 ) );
		drawSprites();
		window->display();

        sf::Time time=clock.getElapsedTime();
        int tempo =time.asMilliseconds();
        Observer<int>::notifyListeners(tempo);

        time=milliseconds(16)-time;
		sf::sleep(time);
		clock.restart();
	}

}


int BasicRenderer::getWidth()
{
	return this->dimX;
}
int BasicRenderer::getHeight()
{
	return dimY;
}
void BasicRenderer::removeDrawable ( sf::Drawable* d )
{
	for ( int i = 0; i < 3; i++ ) {
		sprites[i].remove ( d );


	}
}
void BasicRenderer::addDrawable ( sf::Drawable* d, int i )
{
    i%=3;
	sprites[i].push_back ( d );

}
void BasicRenderer::drawSprites()
{
	View v = window->getView();
	v.setRotation ( camera->rotation );
	v.setCenter ( dimX / 2 + camera->pos.x , dimY / 2 + camera->pos.y );
	v.setSize ( dimX / camera->zoom, dimY / camera->zoom );
	window->setView ( v );

	for ( int i = 0; i < 3; i++ ) {
		for ( Drawable* s : sprites[i] ) {
			window->draw ( *s );
		}
	}
}

void BasicRenderer::createKeyBoardEvent ( sf::Event e )
{

	if ( Event::KeyPressed ) {
		//  std::<<"here";
		for ( int i = 0; i < 100; i++ ) {
			if ( sf::Keyboard::isKeyPressed ( ( Keyboard::Key ) i ) && !keyboard[i] ) {

				KeyBoardReader::notifyListeners ( KeyBoardEvent ( i, KeyBoardEvent::DOWN ) );

				keyboard[i] = true;
			}
		}
	}
	if ( Event::KeyReleased ) {
		for ( int i = 0; i < 100; i++ ) {
			if ( !sf::Keyboard::isKeyPressed ( ( Keyboard::Key ) i ) && keyboard[i] ) {

				KeyBoardReader::notifyListeners ( KeyBoardEvent ( i, KeyBoardEvent::UP ) );

				keyboard[i] = false;
			}
		}
	}
}

pg::Coord BasicRenderer::getMouseCoord()
{
	pg::Coord x = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );
	if ( camera != 0 ) {
		pg::Coord dimension = pg::Coord ( window->getSize().x, window->getSize().y );
		//ajuste de acordo com a camera
		x = ( dimension / 2 - dimension / ( camera->zoom * 2 ) ) + x / camera->zoom;
		//ajuste de acordo com a resolução
		pg::Coord resolution = pg::Coord ( window->getDefaultView().getSize().x, window->getDefaultView().getSize().y ) ;
		resolution = dimension / resolution;
		x = x / resolution;
		x = x + camera->pos;
	}
	return x;
}

void BasicRenderer::createMouseEvent ( sf::Event e )
{
	switch ( e.type ) {
		case Event::MouseButtonPressed: {
				pg::Coord coord = getMouseCoord();
				pg::Coord screenCoord = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );


				if ( Mouse::isButtonPressed ( Mouse::Left ) && !mouse[0] ) {
					MouseReader::notifyListeners ( MouseEvent ( MouseEvent::LEFT_DOWN, coord, screenCoord ) );
					mouse[0] = 1;
				}
				if ( Mouse::isButtonPressed ( Mouse::Middle ) && !mouse[1] ) {
					MouseReader::notifyListeners ( MouseEvent ( MouseEvent::MIDDLE_DOWN, coord, screenCoord ) );
					mouse[1] = 1;
				}
				if ( Mouse::isButtonPressed ( Mouse::Right ) & !mouse[2] ) {
					MouseReader::notifyListeners ( MouseEvent ( MouseEvent::RIGHT_DOWN, coord, screenCoord ) );
					mouse[2] = 1;
				}
				break;

			}
		case Event::MouseButtonReleased: {
				pg::Coord coord = getMouseCoord();
				pg::Coord screenCoord = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );

				if ( !Mouse::isButtonPressed ( Mouse::Left ) && mouse[0] ) {
					MouseReader::notifyListeners ( MouseEvent ( MouseEvent::LEFT_UP, coord, screenCoord ) );
					mouse[0] = 0;
				}
				if ( !Mouse::isButtonPressed ( Mouse::Middle ) && mouse[1] ) {
					MouseReader::notifyListeners ( MouseEvent ( MouseEvent::MIDDLE_UP, coord, screenCoord ) );
					mouse[1] = 0;
				}
				if ( !Mouse::isButtonPressed ( Mouse::Right ) && mouse[2] ) {
					MouseReader::notifyListeners ( MouseEvent ( MouseEvent::RIGHT_UP, coord, screenCoord ) );
					mouse[2] = 0;
				}
				break;

			}

		case Event::MouseMoved: {
				pg::Coord coord = getMouseCoord();
				pg::Coord screenCoord = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );

				MouseReader::notifyListeners ( MouseEvent ( MouseEvent::MOVE, coord, screenCoord ) );
				break;
			}
		case Event::MouseWheelMoved: {
				// 	float x=((Event::MouseWheelEvent)e).delta;
				pg::Coord coord = getMouseCoord();
				pg::Coord screenCoord = pg::Coord ( Mouse::getPosition ( *window ).x, Mouse::getPosition ( *window ).y );
				//e.mouseWheel;
				//       MouseReader::notifyListeners ( MouseEvent ( MouseEvent::MOVE, coord, screenCoord ) );
			}
	}

}
