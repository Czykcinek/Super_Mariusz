#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"
using namespace sf;


//TICK
//pred -=10
//player.y 




class Entity : public Drawable
	, public Transformable
{
private:
	RectangleShape rect;
	bool up;
	bool down;
	bool left;
	bool right;
	bool bieg;
	bool skok;
	float grawitacja = 0;

	float PozX;
	float PozY;

public:
	Sprite m_sprite;
	Texture m_texture;
	VertexArray m_vertices;
	virtual void draw(RenderTarget& target, RenderStates states) const
	{
		// You can draw other high-level objects
		target.draw(m_sprite, states);

	}
	Entity(float x, float y)
	{
		rect.draw(Vector2f(x, y));
		PozX = W1 / 2 - 50;
		PozY = H1 / 2 - 50;
		rect.setPosition(PozX,PozY);
		up = false;
		down = false;
		left = false;
		right = false;
		bieg = false;
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

			if (key == Keyboard::C)
				bieg = true;

			if (key == Keyboard::Space)
			{
				skok = true;
				grawitacja = -1;

			}
		}
		if (checkPressed == false)
		{
			up = false;
			down = false;
			left = false;
			right = false;
			bieg = false;
			skok = false;
			
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

		if (bieg)
		{ 
			if (up)
				movement.y -= 1.5;

			if (down)
				movement.y += 1.5;

			if (left)
				movement.x -= 1.5;

			if (right)
				movement.x += 1.5;
		}
		
		if (skok)
		{
			
			grawitacja += 0.02;
			movement.y += grawitacja;
		}

		rect.move(movement);

	}


	void drawTo(RenderWindow &window)
	{
		window.draw(rect);
	}

	FloatRect getGlobalBounds() const;
};