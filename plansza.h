#pragma once
#include "klocek.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SZEROKOSC_PLANSZY 12
#define WYSOKOSC_PLANSZY 20
#define MACIERZ_KLOCKA 5
class Plansza:public Klocek
{
public:
	friend class Klocek;
	Plansza(int wysokosc_okna);
	void Generator_Klockow(int pozycjaX, int pozycjaY, int rodzaj_klocka, int rotacja);
	void Czyszczenie_klockow(int pozycjaX, int pozycjaY, int rodzaj_klocka, int rotacja);
	bool KoniecGry();
	//ponizsze dwie funkcje polaczone ze soba
	void Kasacja_linii(int pozycjaY);
	void Czy_usuwac_linie();
	bool czy_blok_jest_wolny(int pX, int pY);
	bool czy_ruch_jest_mozliwy(int pX,int pY, int klocek, int rotacja);
	int plansza[WYSOKOSC_PLANSZY][SZEROKOSC_PLANSZY];
	void Generator_Planszy();
	int GetRand();
	int RotujKlocka1(int rotacja);
	int RotujKlocka2(int pX, int pY, int rodzaj_klocka, int rotacja);
	int wys;
};

