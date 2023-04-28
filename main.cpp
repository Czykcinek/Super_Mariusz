#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace sf;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int NUM_COINS = 10;
const float GRAVITY = 9.81f;
const float JUMP_SPEED = -300.0f;
const float MOVE_SPEED = 150.0f;

int main()
{
    // Utw�rz okno o wymiarach 800x600
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Poruszanie postaci� z monetami");

    // Utw�rz posta� jako obiekt RectangleShape
    RectangleShape character(Vector2f(50.0f, 50.0f));
    character.setFillColor(Color::Red);
    character.setPosition(Vector2f(400.0f, 0.0f)); // Ustaw pocz�tkow� pozycj� postaci na g�rze ekranu

    // Ustaw pr�dko�� postaci na pocz�tku
    Vector2f velocity(0.0f, 0.0f);
    float gravity = 9.81f; // Sta�a grawitacji

    // Ustaw warto�ci dla skoku
    bool isJumping = false;
    float jumpVelocity = -12.0f;
    int jumpCount = 0;
    int maxJumpCount = 2;

    // Utw�rz monety jako obiekty RectangleShape
    const int NUM_COINS = 10;
    RectangleShape coins[NUM_COINS];
    for (int i = 0; i < NUM_COINS; i++)
    {
        coins[i].setSize(Vector2f(30.0f, 30.0f));
        coins[i].setFillColor(Color::Yellow);
        coins[i].setPosition(Vector2f((i + 1) * 70.0f, 550.0f));
    }

    // G��wna p�tla programu
    while (window.isOpen())
    {
        // Obs�uga zdarze�
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            }
        }

        // Obs�uga zdarze� (w tym obs�uga skoku)
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Space && jumpCount < 2) // Space = klawisz skoku
            {
                isJumping = true;
                jumpCount++;
            }
        }

        // Aktualizacja pr�dko�ci postaci
        if (isJumping)
        {
            velocity.y = jumpVelocity;
            jumpVelocity += 1.0f; // Dodanie warto�ci przyspieszenia do pr�dko�ci pionowej
        }

        // Poruszanie postaci�
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            character.move(-0.5f, 0.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            character.move(0.5f, 0.0f);
        }

        // Skok postaci
        if (Keyboard::isKeyPressed(Keyboard::Up) && !isJumping && jumpCount < maxJumpCount)
        {
            isJumping = true;
            velocity.y = jumpVelocity;
            jumpCount++;
        }
        if (!Keyboard::isKeyPressed(Keyboard::Up) && isJumping)
        {
            isJumping = false;
        }

        // Obliczanie si�y grawitacji
        velocity.y += gravity * 0.01f;

        // Sprawdzenie kolizji z dolnym brzegiem ekranu
        if (character.getPosition().y + character.getSize().y >= window.getSize().y)
        {
            velocity.y = 0.0f; // Resetowanie pr�dko�ci pionowej
            character.setPosition(character.getPosition().x, window.getSize().y - character.getSize().y); // Ustawienie postaci na dolnym brzegu ekranu
            jumpCount = 0; // Resetowanie licznika skok�w
        }

        // Aktualizacja pozycji postaci na podstawie pr�dko�ci
        character.move(velocity);

        // Sprawdzenie kolizji z monetami
        for (int i = 0; i < NUM_COINS; i++)
        {
            if (coins[i].getGlobalBounds().intersects(character.getGlobalBounds()))
            {
                coins[i].setPosition(-100.0f, -100.0f); // Ukryj monet� po zebraniu przez posta�
                // Dodaj punkty lub inny efekt po zebraniu monety
            }
        }

        // Czyszczenie ekranu i rysowanie postaci i monet
        window.clear();
        window.draw(character);
        for (int i = 0; i < NUM_COINS; i++)
        {
            window.draw(coins[i]);
        }
        window.display();
    }

    return 0;
}
