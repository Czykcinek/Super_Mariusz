#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"
#include "funkcje.cpp"
using namespace sf;


//TICK
//pred -=10
//player.y 




class Entity : public sf::Drawable, public sf::Transformable
	
{
private:
	//RectangleShape rect;
	bool up;
	bool down;
	bool left;
	bool right;
	bool bieg;
	bool skok;
	float grawitacja = 9.0f;
	
	float PozX;
	float PozY;
	float MARIO_SPEED = 0.1; // musi być przypisana wartosc bo nie dziala
	
	const float GRAVITY = 9.81f;
	const float JUMP_SPEED = -300.0f;
	const float MOVE_SPEED = 150.0f;

	// Ustaw wartoscci dla skoku
	bool isJumping = false;
	float jumpVelocity = -12.0f;
	int score;
	Font font;
	sf::Text scoreText;
	int maxJumpCount = 2;
public:
	
	Sprite m_sprite;
	Texture m_texture;
	VertexArray m_vertices;
	float velocityX = 0;
	float velocityY = 0;
	int jumpCount = 0;
	Entity()  :
		PozX(1.5f * W1), //ustawienie pozycji postaci
		PozY(0.5f * H1),
		score(0)
	{
		m_texture.loadFromFile("Resources/Images/MarioBrake.png"); //załadowanie tekstury z pliku
		m_sprite.setTexture(m_texture); //ustawienie tekstury
		
		
		
		//m_texture.setPosition(PozX, PozY);
		up = false;
		down = false;
		left = false;
		right = false;
		bieg = false;

		if (!font.loadFromFile("Resources/Fonts/SuperMario256.ttf")) {
			// obsługa błędu ładowania czcionki
		}

		scoreText.setFont(font);
		scoreText.setCharacterSize(30);
		scoreText.setFillColor(sf::Color::Red);
		scoreText.setPosition(10, 10);
		
	}
	void increaseScore(int points) {
		score += points;
		scoreText.setString("Punkty: " + std::to_string(score));
	}
	int getScore() const {
		return score;
	}
	
	float zero = 0;
	bool colisionX = 0;
	bool colisionY = 0;
	bool colision = 0;
	//Vector2f velocity(0.1f, 0.1f);
	void update(std::vector<sf::RectangleShape>& blocks)
	{
		

		// Obliczanie si³y grawitacji
		//velocity.y += grawitacja * 0.01f;
		

		// Pobierz obwiednię sprita
		sf::FloatRect bounds = m_sprite.getGlobalBounds();
		// Ograniczenie pozycji postaci
		if (PozX < 0) PozX = 0;
		if (PozX > W1 - getGlobalBounds().width) PozX = W1 - getGlobalBounds().width;
		if (PozY > H1) PozY = H1;
		if (PozY < 0) PozY = 0; // dodany warunek, który sprawdza, czy obiekt nie przekroczył górnej granicy ekranu
	
		

			// Przemieszczenie postaci
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				velocityX -= MARIO_SPEED;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				velocityX += MARIO_SPEED;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				velocityY -= MARIO_SPEED;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				velocityY += MARIO_SPEED;
			}
			PozX = velocityX;
			
			if (!colision)
			{
				
				PozY = velocityY;
			}
			
			// Ograniczenie pozycji postaci
			if (PozX < 0) PozX = 0;
			if (PozX > W1 - getGlobalBounds().width) PozX = W1 - getGlobalBounds().width;
			if (PozY > H1) PozY = H1;
		

		
		

	}
	//obsluga getSize,  zwraca rozmiar (szerokość i wysokość) obiektu m_sprite w postaci wektora sf::Vector2f
	sf::Vector2f getSize() const
	{
		return sf::Vector2f(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);
	}

	void draw(RenderWindow& i_window)
	{
		m_sprite.setPosition(round(PozX), round(PozY));
		i_window.draw(m_sprite);
		i_window.draw(scoreText);
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


	//jest to potrzebne do dziedziczenia z drawable oraz transformable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//zwracanie kolizji sprite'a
FloatRect getGlobalBounds() const {
	return getTransform().transformRect(m_sprite.getGlobalBounds());
};

	
};