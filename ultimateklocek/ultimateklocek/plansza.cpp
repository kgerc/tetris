#include <SFML\Graphics.hpp>
#include "plansza.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "klocek.h"
#include <iostream>

using namespace std;

int skrrt = 0;

Plansza::Plansza(int wysokosc_okna)
{
	wys = wysokosc_okna;
}
void Plansza::Generator_Planszy()
{
	for (int i = 0; i < WYSOKOSC_PLANSZY; i++)
	{
		if (i == 19)
		{
			for (int j = 0; j < SZEROKOSC_PLANSZY; j++)
			{
				plansza[i][j] = 8;
			}
			break;
		}
		for (int j = 0; j < SZEROKOSC_PLANSZY; j++)
		{
			if (plansza[i][j] != 1)
			{
				if (j == 0 || j == 11)
				{
					plansza[i][j] = 8;
				}
				else
				{
					plansza[i][j] = 9;
				}
			}
		}
	}
	//tymczasowe rozwiazanie konsolowe
	for (int i = 0; i < WYSOKOSC_PLANSZY; i++)
	{
		if (i == 19)
		{
			for (int j = 0; j < SZEROKOSC_PLANSZY; j++)
			{
				cout << plansza[i][j];
			}
			break;
		}
		for (int j = 0; j < SZEROKOSC_PLANSZY; j++)
		{
			if (j == 0 || j == 11 || plansza[i][j] == 1)
			{
				cout << plansza[i][j];
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
void Plansza::Generator_Klockow(int pozycjaX, int pozycjaY, int rodzaj_klocka, int rotacja)
{
	for (int i = pozycjaX, i2 = 0; i < pozycjaX + MACIERZ_KLOCKA; i++, i2++)
	{
		for (int j = pozycjaY, j2 = 0; j < pozycjaY + MACIERZ_KLOCKA; j++, j2++)
		{
			if (TypKlocka(rodzaj_klocka, rotacja, i2, j2) != 0)
			{
				plansza[i][j] = 1;
			}
		}
	}
}
void Plansza::Czyszczenie_klockow(int pozycjaX, int pozycjaY, int rodzaj_klocka, int rotacja)
{
	for (int i = pozycjaX, i2 = 0; i < pozycjaX + MACIERZ_KLOCKA; i++, i2++)
	{
		for (int j = pozycjaY, j2 = 0; j < pozycjaY + MACIERZ_KLOCKA; j++, j2++)
		{
			if (TypKlocka(rodzaj_klocka, rotacja, i2, j2) == 1)
			{
				plansza[i][j] = 9;

			}
		}
	}
}
bool Plansza::KoniecGry()
{
	for (int i = 0; i < SZEROKOSC_PLANSZY; i++)
	{
		if (plansza[0][i] == 1)
			return true;
	}
	return false;
}
void Plansza::Kasacja_linii(int pozycjaY)
{
	for (int i = pozycjaY; i > 0; i--)
	{
		for (int j = 1; j <= SZEROKOSC_PLANSZY - 2; j++)
		{
			plansza[i][j] = plansza[i - 1][j];
		}
	}
	skrrt += 10;
}
void Plansza::Czy_usuwac_linie()
{
	for (int i = 0; i < WYSOKOSC_PLANSZY; i++)
	{
		int licznik = 0;
		for (int j = 1; j <= SZEROKOSC_PLANSZY - 2; j++)
		{
			if (plansza[i][j] == 1)
			{
				licznik++;
			}
		}
		if (licznik == 10)
		{
			Kasacja_linii(i);
		}
	}
}
bool Plansza::czy_ruch_jest_mozliwy(int pX, int pY, int rodzaj_klocka, int rotacja)
{
	for (int i1 = pX, i2 = 0; i1 < pX + MACIERZ_KLOCKA; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + MACIERZ_KLOCKA; j1++, j2++)
		{
			if (i1 < 0 || i1 > WYSOKOSC_PLANSZY - 1 || j1 > SZEROKOSC_PLANSZY - 1)
			{
				if (TypKlocka(rodzaj_klocka, rotacja, i2, j2) != 0)
				{
					return 0;
				}
			}
			if (j1 >= 0)
			{
				if ((TypKlocka(rodzaj_klocka, rotacja, i2, j2) != 0) && (plansza[i1][j1] != 9))
					return false;
			}
		}
	}
	return true;
}
int::Plansza::GetRand()
{
	srand(time(NULL));
	return rand() % 7;
}
int::Plansza::RotujKlocka1(int rotacja)
{
	if (rotacja < 3)
	{
		rotacja++;
	}
	else
	{
		rotacja = 0;
	}
	return rotacja;
}
int Plansza::RotujKlocka2(int pX, int pY, int rodzaj_klocka, int rotacja)
{
	if (rodzaj_klocka == 1)
	{
		if ((pY == -1 || plansza[pX + 2][pY + 1] == 1 || plansza[pX + 1][pY + 2] == 1) && rotacja == 2)
		{
			pY = pY + 2;
		}
		if ((pY == 0 || plansza[pX + 2][pY + 2] == 1 || plansza[pX + 1][pY + 2] == 1) && rotacja == 2)
		{
			pY = pY + 1;
		}
		if ((pY == -1 || plansza[pX + 2][pY + 1] == 1 || plansza[pX + 1][pY + 2] == 1) && rotacja == 0)
		{
			pY = pY + 1;
		}
		if ((pY == 8 || plansza[pX + 2][pY + 3] == 1 || plansza[pX + 1][pY + 2] == 1) && rotacja == 0)
		{
			pY = pY - 2;
		}
		if ((pY == 7 || plansza[pX + 2][pY + 4] == 1 || plansza[pX + 1][pY + 2] == 1) && rotacja == 0)
		{
			pY = pY - 1;
		}
		if ((pY == 8 || plansza[pX + 2][pY + 3] == 1 || plansza[pX + 1][pY + 2] == 1) && rotacja == 2)
		{
			pY = pY - 1;
		}
	}
	else if ((pY < 0 || plansza[pX + 2][pY + 1] == 1 || plansza[pX + 3][pY + 1] == 1) && rodzaj_klocka != 0)
	{
		pY = pY + 1;
	}
	else if ((pY > 7 || plansza[pX + 1][pY + 3] == 1 || plansza[pX + 2][pY + 3] == 1) && rodzaj_klocka != 0)
	{
		pY = pY - 1;
	}
	return pY;
}
int Plansza::RotujKlocka3(int pX, int pY, int rodzaj_klocka, int rotacja)
{
	if (rodzaj_klocka == 1)
	{
		if ((pX == -2 || plansza[pX + 1][pY + 2] == 1) && rotacja == 1)
		{
			pX = pX + 1;
		}
		if ((pX == -2 || plansza[pX + 1][pY + 2] == 1) && rotacja == 3)
		{
			pX = pX + 2;
		}
		if ((rotacja == 3 || plansza[pX + 1][pY + 2] == 1) && (pX == -1 || pX == -2))
		{
			pX = pX + 1;
		}
		if ((pX == 16 || plansza[pX + 3][pY] == 1) && rotacja == 1)
		{
			pX = pX - 2;
		}
		if ((pX == 15 || plansza[pX + 4][pY] == 1) && rotacja == 1)
		{
			pX = pX - 1;
		}
		if ((rotacja == 3 || plansza[pX + 3][pY] == 1) && pX == 16)
		{
			pX = pX - 1;
		}
	}
	else if ((pX == -2 || plansza[pX + 1][pY + 1] == 1 || plansza[pX + 1][pY + 2] == 1) && rodzaj_klocka != 0)
	{
		pX = pX + 1;
	}
	else if ((pX == 16 || plansza[pX + 3][pY + 2] == 1 || plansza[pX + 3][pY + 3] == 1) && rodzaj_klocka != 0)
	{
		pX = pX - 1;
	}
	return pX;
}
void::Plansza::RotujKlocka4(int pX, int pY, int rodzaj_klocka, int rotacja)
{
	for (int i1 = pX, i2 = 0; i1 < pX + MACIERZ_KLOCKA; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + MACIERZ_KLOCKA; j1++, j2++)
		{
			if (TypKlocka(rodzaj_klocka, rotacja, i2, j2) != 0)
			{
				plansza[i1][j1] = 1;
			}
		}
	}
}

bool::Plansza::czy_mozna_rotowac(int pX, int pY, int rodzaj_klocka, int rotacja)
{
	int licznik = 0;
	for (int i1 = pX, i2 = 0; i1 < pX + MACIERZ_KLOCKA; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + MACIERZ_KLOCKA; j1++, j2++)
		{
			if (TypKlocka(rodzaj_klocka, rotacja, i2, j2) != 0 && (plansza[i1][j1] == 1 || plansza[i1][j1] == 8))
			{
				licznik++;
			}
		}
	}
	if (licznik != 0)
	{
		return false;
	}
	else
		return true;
}

int::Plansza::Pozycja_poczatkowa_x(int rodzaj_klocka, int rotacja)
{
	return PozycjaXInit(rodzaj_klocka, rotacja);
}
int::Plansza::Pozycja_poczatkowa_y(int rodzaj_klocka, int rotacja)
{
	return PozycjaYInit(rodzaj_klocka, rotacja);
}
void::Plansza::Generujklocka(sf::RenderWindow& window, sf::VertexArray& M)
{
	for (int i = 0; i < WYSOKOSC_PLANSZY; i++)
	{
		for (int j = 0; j < SZEROKOSC_PLANSZY; j++)
		{
			if (plansza[i][j] == 1)
			{
				sf::RectangleShape klocek1(sf::Vector2f(50.0f, 50.0f));
				sf::Texture cubetexture;
				cubetexture.loadFromFile("textury/cube.png");
				klocek1.setTexture(&cubetexture);


				klocek1.setPosition(M[(i)*12+(j)].position);


				window.draw(klocek1);
			}

		}
	}
}


void scorr(sf::RenderWindow& window)
{

	int scr = 0;
	scr = skrrt;
	std::string score = std::to_string(scr);
	if (scr < 10)
		score = "000" + score;
	else if (scr < 100)
		score = "00" + score;
	else if (scr < 1000)
		score = "0" + score;

	sf::Font czcionka;
	czcionka.loadFromFile("font/scorefont.ttf");
	sf::Text scre(score, czcionka);
	scre.setFillColor(sf::Color(217, 141, 255));
	scre.setCharacterSize(100);
	scre.setPosition(710, 250);


	window.draw(scre);
}