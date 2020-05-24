#include "plansza.h"
#include "klocek.h"
#include <iostream>
using namespace std;
Plansza::Plansza(int wysokosc_okna)
{
	wys = wysokosc_okna;
}
void Plansza::Generator_Planszy()
{
	for (int i = 0; i < WYSOKOSC_PLANSZY;i++)
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
			if (j == 0 || j == 11||plansza[i][j]==1)
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
	for (int i = pozycjaX,i2=0; i <pozycjaX + MACIERZ_KLOCKA; i++,i2++)
	{
		for (int j = pozycjaY,j2=0; j <pozycjaY + MACIERZ_KLOCKA; j++,j2++)
		{
			if (TypKlocka(rodzaj_klocka, rotacja, i2, j2)!=0)
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
	for (int i = pozycjaY; i < 0; i--)
	{
		for (int j = 0; j < SZEROKOSC_PLANSZY; j++)
		{
			plansza[i][j] = plansza[i - 1][j];
		}
	}
}
void Plansza::Czy_usuwac_linie()
{
	for (int i = 0; i < WYSOKOSC_PLANSZY; i++)
	{
		int licznik = 0;
		for(int j = 0; j < SZEROKOSC_PLANSZY; j++)
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
			if (i1 < 0 || i1 > WYSOKOSC_PLANSZY-1|| j1 > SZEROKOSC_PLANSZY-1)
			{
				if (TypKlocka(rodzaj_klocka, rotacja, i2, j2) != 0)
				{
					return 0;
				}
			}
			if (j1 >= 0)
			{
				if ((TypKlocka(rodzaj_klocka, rotacja, i2, j2) != 0) && (plansza[i1][j1]!=9))
					return false;	
			}
		}
	}
	return true;
}
