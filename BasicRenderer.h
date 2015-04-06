#ifndef BASICRENDERER_H
#define BASICRENDERER_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <ProjGaia/Tools/KeyBoardEvent.h>
#include <ProjGaia/Tools/NeedsUpdate.h>
#include <ProjGaia/Tools/Observer.h>
#include <ProjGaia/Graphics/Camera.h>
#include <ProjGaia/Graphics/KeyBoardReader.h>
#include <ProjGaia/Graphics/MouseReader.h>
#include <list>
#include <thread>

class BasicRenderer :public pg::MouseReader, public pg::KeyBoardReader, public pg::Observer<int>
{
    public:
        /** Default constructor */
        BasicRenderer( std::string window_name , int width, int height );

        virtual ~BasicRenderer();

        void beginAssync();
        void begin();
        int getWidth();
        int getHeight();

        void removeDrawable ( sf::Drawable* );
		void addDrawable ( sf::Drawable*, int =1);


		pg::Coord getMouseCoord();
    protected:
        void createMouseEvent ( sf::Event );
		void createKeyBoardEvent ( sf::Event );
        void drawSprites();

        std::list<sf::Drawable*> sprites[3];
		sf::RenderWindow* window;
		pg::Camera* camera;
		std::thread* assync;


    private:
        std::string name;


        bool mouse[3] = {0, 0, 0}; //mouse timers
		bool keyboard[100] = {0};
		int dimX;
		int dimY;
};

#endif // BASICRENDERER_H
