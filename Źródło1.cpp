#include <iostream>
#include "klocek.h"
#include "plansza.h"
using namespace std;

int main()
{
	int x;
	int x1=-1, y1=1,r_klocka=1,rotacja=1;
	Plansza p1(20);
	p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
	p1.Generator_Planszy();
	for (int i = 0; i < 100; i++)
	{
		cout << endl<< "kierunek:";
		cin >> x;
		switch (x)
		{
		case 1:
		{
			p1.Czyszczenie_klockow(x1, y1, r_klocka, rotacja);
			if (p1.czy_ruch_jest_mozliwy(x1 + 1, y1, r_klocka, rotacja))
			{
				p1.Generator_Klockow(x1 + 1, y1, r_klocka, rotacja);
				x1++;
			}
			else
			{
				p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
				x1 = 1;
				y1 = 1;
				r_klocka = p1.GetRand();
				p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
			}

		}
		break;
		case 2:
		{
			p1.Czyszczenie_klockow(x1, y1, r_klocka, rotacja);
			if (p1.czy_ruch_jest_mozliwy(x1, y1 + 1, r_klocka, rotacja))
			{
				p1.Generator_Klockow(x1, y1 + 1, r_klocka, rotacja);
				y1++;
			}
			else
			{
				p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
			}
		}
		break;

		case 3:
		{
			p1.Czyszczenie_klockow(x1, y1, r_klocka, rotacja);
			if (p1.czy_ruch_jest_mozliwy(x1, y1 - 1, r_klocka, rotacja))
			{
				p1.Generator_Klockow(x1, y1 - 1, r_klocka, rotacja);
				y1--;
			}
			else
			{
				p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
			}
		}
		break;
		case 4:
		{
			p1.Czyszczenie_klockow(x1, y1, r_klocka, rotacja);
			rotacja = p1.RotujKlocka1(rotacja);
			y1 = p1.RotujKlocka2(x1, y1, r_klocka, rotacja);
		}
		break;
		}
		system("cls");
		p1.Generator_Planszy();
	}
	return 0;
}