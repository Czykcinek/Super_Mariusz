#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Entity
{
private:
	RectangleShape rect;
	bool up;
	bool down;
	bool left;
	bool right;

	float PozX;
	float PozY;

public:
	Entity(float x, float y)
	{
		rect.setSize(Vector2f(x, y));
		PozX = W1 / 2 - 50;
		PozY = H1 / 2 - 50;
		rect.setPosition(PozX,PozY);
		up = false;
		down = false;
		left = false;
		right = false;
	}
	void processEvents(Keyboard::Key key, bool checkPressed)
	{
		if (checkPressed == true)
		{
			if (key == Keyboard::W)
				up = true;

			if (key == Keyboard::S)
				down = true;

			if (key == Keyboard::A)
				left = true;

			if (key == Keyboard::D)
				right = true;

		}
		if (checkPressed == false)
		{
			up = false;
			down = false;
			left = false;
			right = false;

		}

	}

	void update()
	{
		Vector2f movement;
		if (up)
			movement.y -= 0.5;

		if (down)
			movement.y += 0.5;

		if (left)
			movement.x -= 0.5;

		if (right)
			movement.x += 0.5;

		rect.move(movement);

	}


	void drawTo(RenderWindow &window)
	{
		window.draw(rect);
	}


};