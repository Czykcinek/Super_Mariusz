//Super Mariusz, gierka na zaliczenie projektu z przedmiotu In¿ynieria oprogramowania.

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window{ VideoMode{1280,720}, "Super_Mariusz" };
	window.setFramerateLimit(144);

	RectangleShape shape(Vector2f(300, 300));
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