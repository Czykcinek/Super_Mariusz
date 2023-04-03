#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"
#include "funkcje.cpp"
using namespace sf;


//TICK
//pred -=10
//player.y 




class Entity 
	
{
private:
	//RectangleShape rect;
	bool up;
	bool down;
	bool left;
	bool right;
	bool bieg;
	bool skok;
	float grawitacja = 0;

	float PozX;
	float PozY;
	float MARIO_SPEED;
public:
	Sprite m_sprite;
	Texture m_texture;
	VertexArray m_vertices;
	
	Entity(/*float x, float y*/)  :
		PozX(0.5f * W1), //ustawienie pozycji postaci
		PozY(0.5f * H1) 
	{
		m_texture.loadFromFile("Resources/Images/MarioBrake.png"); //za³adowanie tekstury z pliku
		m_sprite.setTexture(m_texture); //ustawienie tekstury
		
		
		
		//m_texture.setPosition(PozX, PozY);
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
		if (1 == Keyboard::isKeyPressed(Keyboard::Left))
		{
			PozX -= MARIO_SPEED;
		}
		else if (1 == Keyboard::isKeyPressed(Keyboard::Right))
		{
			PozY += MARIO_SPEED;
		}
		/*Vector2f movement;
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

		m_sprite.move(movement);*/

	}
	
	void draw(RenderWindow& i_window)
	{
		m_sprite.setPosition(round(PozX), round(PozY));
		i_window.draw(m_sprite);
	}
	
	//void draw(RenderWindow& i_window); //rysowanie tekstur mario
	
	/*
	void drawTo(RenderWindow &window)
	{
		m_sprite.setPosition(round(PozX),round(PozY))
	}
	*/
	/*
	FloatRect getGlobalBounds() const;
	*/

};