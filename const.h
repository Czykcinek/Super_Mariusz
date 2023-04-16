#pragma once
//tutaj sta³e

const unsigned char RozmiarKratki = 16;
const unsigned char RozciaganieEkranu = 2;
const int R = 100;
const int SP = 55; //szerokosc prostokata
const int WP = 44; //wysokosc prostokata
const int W1 = 240; //szerokosc ekranu
const int H1 = 256; //wysokosc	ekranu


enum Cell	//nie wiem 
{
		Empty,
		Wall
};

typedef std::vector < std::array<Cell, H1 / RozmiarKratki >> Map; //potrzebne do stworzenia mapy



