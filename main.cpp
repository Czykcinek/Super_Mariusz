//Super Mariusz, gierka na zaliczenie projektu z przedmiotu In¿ynieria oprogramowania.

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

using namespace sf;
using namespace std;

int main()
{
	setlocale(LC_ALL, ""); //zachowanie polskiej czcionki w konsoli.

	RenderWindow window{ VideoMode{1280, 720, 32}, "Super_Mariusz" }; //Tworzenie okna o rozmiarach 1280x720px i nazwie Super_Mariusz.
	window.setFramerateLimit(144); // Ustawienie limitu klatek na sekundê.

	RectangleShape shape(Vector2f(300, 300)); // Tworzenie obiektu 
	shape.setFillColor(Color::Blue);
	
	while (window.isOpen())
	{
		Event event;
		while (true)
		{
			window.clear(Color::Green);
			window.pollEvent(event);

			if (event.type == Event::Closed)
			{
				window.close();
				break;
			}
			window.draw(shape);
			window.display();
		}
	}

	return 0;
}