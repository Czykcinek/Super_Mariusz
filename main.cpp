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


void drawMap(unsigned i_view_x, const sf::Image& i_map_sketch, sf::RenderWindow& i_window, const sf::Texture& i_map_texture, const Map& i_map)
{

    {
        Sprite cell_sprite(i_map_texture);
        unsigned short sprite_x = 0;
        unsigned short sprite_y = 0;
        for (unsigned short a = 0; a < i_map.size(); a++)
        {

            for (unsigned short b = 0; b < i_map[a].size(); b++)
            {
                if (Cell::Empty == i_map[a][b])
                {
                    continue;
                }
                else if (Cell::Wall == i_map[a][b])
                {
                    sprite_y = 0;
                    sprite_x = 1;

                    //if (sf::Color(0, 0, 0) == i_map_sketch.getPixel(a, b)) //Walls
                    //{
                    //    sprite_x = 2;
                    //}
                    //else //Solid blocks
                    //{
                    //    sprite_x = 3;
                    //}
                }
                cell_sprite.setPosition(RozmiarKratki * a, RozmiarKratki * b);

                cell_sprite.setTextureRect(sf::IntRect(RozmiarKratki * sprite_x, RozmiarKratki * sprite_y, RozmiarKratki, RozmiarKratki));

                i_window.draw(cell_sprite);
            }








        }


    }
}
/*
struct vector2f
{
float x;
float y;
}
*/



int main()
{
    RenderWindow window(VideoMode(RozciaganieEkranu * W1, RozciaganieEkranu * H1), "Super_Mariusz"); //otworzenie okna
    window.setPosition(Vector2i(window.getPosition().x, window.getPosition().y - 90));
    window.setView(View(FloatRect(0, 0, W1, H1)));
    //RectangleShape shape(Vector2f(SP, WP));
   // shape.setPosition(W1 / 2 - SP, H1 / 2 - WP);
   // shape.setFillColor(Color::Blue);
   
    RectangleShape podloga(Vector2f(W1, 50)); //stworzenie podlogi

        podloga.setPosition(0, H1);
        podloga.setFillColor(Color::Blue);
       
        Texture map_texture;
        map_texture.loadFromFile("Resources/Images/Map.png");

        Map map(W1 / RozmiarKratki);
        Entity player; //??????????????????????????????????????????????????????????? czemu to nie dzia³a


        for (unsigned short a = 0; a < map.size(); a++)
        {
            for (unsigned short b = map[a].size() - 2; b < map[a].size(); b++)
            {
                map[a][b] = Cell::Wall;
            }
        }




       /* FloatRect boundingBox = player.getGlobalBounds();
        FloatRect PodlogaBox = podloga.getGlobalBounds();
   */


    while (window.isOpen())
    {
       //// window.clear(Color::Green);
       // Event event;
       // while (window.pollEvent(event))
       // {
       //     
       //    //shape.move(0.1, 0);
       //     window.pollEvent(event);

       //     if (event.type == Event::Closed)
       //         window.close();

       //     if (event.type == Event::KeyPressed) //poruszanie sie, jesli nacisniete
       //         player.processEvents(event.key.code, true);

       //     
       //     if (event.type == Event::KeyReleased)
       //         player.processEvents(event.key.code, false);

       // }

        window.clear();
        player.update(); //aktualizacja pozycji 
        window.draw(podloga); //rysuje podloge
       player.draw(window); //rysuje postac
       
        

       /* player.drawTo(window);*/
        window.display();
       
    }
    return 0;
}