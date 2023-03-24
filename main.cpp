//Super Mariusz, gierka na zaliczenie projektu z przedmiotu In¿ynieria oprogramowania.

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "const.h"
#include "funkcje.h"
#include "entity.h"
using namespace sf;
using namespace std;




/*
struct vector2f
{
float x;
float y;
}
*/



int main()
{
    RenderWindow window(VideoMode(W1, H1), "Super_Mariusz");
    //RectangleShape shape(Vector2f(SP, WP));
   // shape.setPosition(W1 / 2 - SP, H1 / 2 - WP);
   // shape.setFillColor(Color::Blue);

    Entity player(50,50);

   


    while (window.isOpen())
    {
       // window.clear(Color::Green);
        Event event;
        while (window.pollEvent(event))
        {
            
           // shape.move(0.1, 0);
           // window.pollEvent(event);
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
                player.processEvents(event.key.code, true);

            
            if (event.type == Event::KeyReleased)
                player.processEvents(event.key.code, false);


        }
        window.clear();
        player.update();
        //window.draw(shape);

        player.drawTo(window);
        window.display();
       
    }
    return 0;
}