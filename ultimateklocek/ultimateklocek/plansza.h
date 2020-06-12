#pragma once
#include <SFML\Graphics.hpp>
#include "klocek.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define SZEROKOSC_PLANSZY 12
#define WYSOKOSC_PLANSZY 20
#define MACIERZ_KLOCKA 5



class Plansza :public Klocek
{
public:
	//Konstruktor i zmienne
	friend class Klocek;
	Plansza(int wysokosc_okna);
	int wys;
	int plansza[WYSOKOSC_PLANSZY][SZEROKOSC_PLANSZY];
	//FUNKCJE
	void Generator_Klockow(int pozycjaX, int pozycjaY, int rodzaj_klocka, int rotacja);
	void Generator_Planszy();
	void Czyszczenie_klockow(int pozycjaX, int pozycjaY, int rodzaj_klocka, int rotacja);
	bool czy_ruch_jest_mozliwy(int pX, int pY, int klocek, int rotacja);
	//ponizsze 6 funkcji w parach
	void Kasacja_linii(int pozycjaY);
	void Czy_usuwac_linie();
	//wersja 1 odpowiada jedynie za zmiane wartosci zmiennej "rotacja"
	int RotujKlocka1(int rotacja);
	//wersja 2 odpowiada za rotowanie klocka z uwzglednieniem bocznych kolizji przy generowaniu zrotowanego klocka
	int RotujKlocka2(int pX, int pY, int rodzaj_klocka, int rotacja);
	//wersja 3 odpowiada za rotowanie klocka z uwzglednieniem górnej kolizji(wiersz 0) przy generowaniu zrotowanego klocka
	int RotujKlocka3(int pX, int pY, int rodzaj_klocka, int rotacja);
	int Pozycja_poczatkowa_x(int rodzaj_klocka, int rotacja);
	int Pozycja_poczatkowa_y(int rodzaj_klocka, int rotacja);
	//Generator randomowego klocka i warunek koñca gry
	int GetRand();
	bool KoniecGry();
	void Generujklocka(sf::RenderWindow& window, sf::VertexArray& M);
};

void scorr(sf::RenderWindow& window);