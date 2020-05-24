#pragma once
#include "plansza.h"
#include "klocek.h"
#include <time.h>
//tutaj wrzuc #define czas oczekiwania klocka na ruch
class gra
{
public:
	gra(Plansza* mplansza, Klocek* mklocek, int wysokosc_okna){};
	void StworzNowyKloc();
private:
	int Random(int pA, int pB);
	void GierkaGoesBrrrr();
	void NarysujKloca();
	void NarysujPlansze();
};

