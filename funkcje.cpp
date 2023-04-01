
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "const.h"
#include "entity.h"

using namespace sf;
using namespace std;
#include "entity.h"
//definicje funkcji


//przesun(4.1, 0, shape);
//void przesun(float PX, float PY, CircleShape& obiektdoprzes)
//{
//	//przesuniecie
//	obiektdoprzes.move(PX, PY);
//	if (obiektdoprzes.getPosition().x > W1)
//		obiektdoprzes.setPosition(0, H1 / 2 - R);
//
//}

void draw_map(RenderWindow& i_window, const Texture& i_map_texture, const Map& i_map)
{
	Sprite cell_sprite(i_map_texture);

		for (unsigned short a = 0; a < i_map.size(); a++)
		{

			for (unsigned short b = 0; b < i_map[a].size(); b++)
			{
				if (Cell::Empty == i_map[a][b])
					continue;

				cell_sprite.setPosition(RozmiarKratki * a, RozmiarKratki * b);
					



			}








		}


}