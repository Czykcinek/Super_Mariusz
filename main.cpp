//Super Mariusz, gierka na zaliczenie projektu z przedmiotu Inżynieria oprogramowania.
//mapa
//zbieranie monet
//punkty
//koniec gry
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
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_sprite, states);
}


int main()
{
    
    int licznikCoin = 0;
    Texture coinTexture;
   //ustawienie tekstury coina
    coinTexture.loadFromFile("Resources/Images/Coin.png");

    std::vector<sf::RectangleShape> blocks;//definicja blocks

    //tekstura mapy
    Texture mapTexture;
    if (!mapTexture.loadFromFile("Resources/Images/grass.png"))
    {
        return EXIT_FAILURE;
    }
    mapTexture.setRepeated(true); // ustawienie powtarzania tekstury
 
    RenderWindow window(VideoMode(/*RozciaganieEkranu **/ W1, /*RozciaganieEkranu*//* **/ H1), "Super_Mariusz"); //otworzenie okna
    window.setPosition(Vector2i(window.getPosition().x, window.getPosition().y - 90));
    window.setView(View(FloatRect(0, 0, W1, H1)));
   


    //Tworzenie platformy
        RectangleShape platform(Vector2f(200, 16));
    platform.setFillColor(Color::White);
    platform.setTexture(&mapTexture);
    platform.setTextureRect(sf::IntRect(0, 0, 200, 16)); // ustawienie fragmentu tekstury odpowiadającego platformie
    platform.setPosition(1.0f, 163.0f);

    RectangleShape platform2(Vector2f(200, 16));
    platform2.setFillColor(Color::White);
    platform2.setTexture(&mapTexture);
    platform2.setTextureRect(sf::IntRect(0, 0, 200, 16)); // ustawienie fragmentu tekstury odpowiadającego platformie
    platform2.setPosition(500.0f, 400.0f);


    RectangleShape platform3(Vector2f(50, 16));
    platform3.setFillColor(Color::White);
    platform3.setTexture(&mapTexture);
    platform3.setTextureRect(sf::IntRect(0, 0, 200, 16)); // ustawienie fragmentu tekstury odpowiadającego platformie
    platform3.setPosition(412.0f, 444.0f);

    RectangleShape platform4(Vector2f(80, 16));
    platform4.setFillColor(Color::White);
    platform4.setTexture(&mapTexture);
    platform4.setTextureRect(sf::IntRect(0, 0, 200, 16)); // ustawienie fragmentu tekstury odpowiadającego platformie
    platform4.setPosition(350.0f, 360.0f);


    // Utw�rz monety jako obiekty RectangleShape
    const int NUM_COINS = 10;
    sf::Sprite coins[NUM_COINS];
    //RectangleShape coins[NUM_COINS];
    for (int i = 0; i < NUM_COINS; i++)
    {
        coins[i].setTexture(coinTexture);
        coins[i].setTextureRect(sf::IntRect(0, 0, 16, 16));
        /*coins[i].setSize(Vector2f(3.0f, 3.0f));
        coins[i].setFillColor(Color::Yellow);*/
        coins[i].setPosition(Vector2f((i + 1) * 23.0f, 140.0f));
    }
   
    const int NUM_COINS2 = 3;
    sf::Sprite coins2[NUM_COINS2];
    //RectangleShape coins[NUM_COINS];
    for (int i = 0; i < NUM_COINS2; i++)
    {
        coins2[i].setTexture(coinTexture);
        coins2[i].setTextureRect(sf::IntRect(0, 0, 16, 16));
        coins2[i].setPosition(Vector2f((i + 1) * 500.0f, 380.0f));
    }

    RectangleShape podloga(Vector2f(W1, 50)); //stworzenie podlogi

        podloga.setPosition(0, H1);
        podloga.setFillColor(Color::Blue);
       
        Texture map_texture;
        map_texture.loadFromFile("Resources/Images/Map.png");

        Map map(W1 / RozmiarKratki);
        Entity player; 

      /*  for (unsigned short a = 0; a < map.size(); a++)
        {
            for (unsigned short b = map[a].size(0) - 2; b < map[a].size(); b++)
            {
                map[a][b] = Cell::Wall;

            }
        }
       */



     

        while (window.isOpen() && licznikCoin < 10)
    {
      
           
            // Sprawdzenie kolizji z platformą
            if (player.getGlobalBounds().intersects(platform.getGlobalBounds()))
            {
                player.colision = 1;
                /*player.velocityX = 0;
                player.velocityY = 0;*/
               /* player.setPosition(player.getPosition().x, platform.getPosition().y - 0.5f);*/
              
            }
            else
            {
                player.colision = 0;
            }

          // Sprawdzenie kolizji z monetami
        for (int i = 0; i < NUM_COINS; i++)
        {
            if (coins[i].getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                coins[i].setPosition(-100.0f, -100.0f); // Ukryj monet� po zebraniu przez posta�
                // Dodaj punkty lub inny efekt po zebraniu monety
                licznikCoin++;
                player.increaseScore(20);
                
            }
        }
     
        // Sprawdzenie kolizji z monetami 2
        for (int i = 0; i < NUM_COINS2; i++)
        {
            if (coins2[i].getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                coins2[i].setPosition(-100.0f, -100.0f); // Ukryj monet� po zebraniu przez posta�
                // Dodaj punkty lub inny efekt po zebraniu monety
                licznikCoin++;
                player.increaseScore(20);

            }
        }
        

        //// Sprawdzenie kolizji z dolnym brzegiem ekranu
        //if (player.getPosition().y + player.getSize().y >= window.getSize().y)
        //{
        //    player.velocity.y = 0.0f; // Resetowanie prêdkoœci pionowej
        //    character.setPosition(character.getPosition().x, window.getSize().y - character.getSize().y); // Ustawienie postaci na dolnym brzegu ekranu
        //    player.jumpCount = 0; // Resetowanie licznika skoków
        //}
      
       
        window.clear();
        player.draw(window); //rysuje postac
        player.update(blocks); //aktualizacja pozycji 
        window.draw(podloga); //rysuje podloge
        /*drawMap2(window);*/
        window.draw(platform);
        window.draw(platform2);
        window.draw(platform3);
        window.draw(platform4);
       for (int i = 0; i < NUM_COINS; i++)
       {
           window.draw(coins[i]);
       }
      
       for (int i = 0; i < NUM_COINS2; i++)
       {
           window.draw(coins2[i]);
       }

       /* player.drawTo(window);*/
        window.display();
       
    }
    return 0;
}