#include <iostream>
#include "klocek.h"
#include "plansza.h"
using namespace std;

int main()
{
	int x;
	int x1=1, y1=1;
	Plansza p1(20);
	p1.Generator_Klockow(1, 1, 6, 2);
	p1.Generator_Planszy();
	for (int i = 0; i < 20; i++)
	{
		cout << endl<< "kierunek:";
		cin >> x;
		switch (x)
		{
		case 1:
		{
				p1.Czyszczenie_klockow(x1, y1, 6, 2);
				if (p1.czy_ruch_jest_mozliwy(x1 + 1, y1, 6, 2))
				{
					p1.Generator_Klockow(x1 + 1, y1, 6, 2);
					x1++;
				}
				else
				{
					p1.Generator_Klockow(x1, y1, 6, 2);
				}
		}
		break;
		case 2:
		{
			p1.Czyszczenie_klockow(x1,y1, 6, 2);
			if (p1.czy_ruch_jest_mozliwy(x1, y1+1, 6, 2))
			{
				p1.Generator_Klockow(x1, y1 + 1, 6, 2);
				y1++;
			}
			else
			{
				p1.Generator_Klockow(x1, y1, 6, 2);
			}
		}
		break;

		case 3:
		{
			p1.Czyszczenie_klockow(x1, y1, 6, 2);
			if (p1.czy_ruch_jest_mozliwy(x1, y1 - 1, 6, 2))
			{
				p1.Generator_Klockow(x1, y1 - 1, 6, 2);
				y1--;
			}
			else
			{
				p1.Generator_Klockow(x1, y1, 6, 2);
			}
		}
		break;
		}
		system("cls");
		p1.Generator_Planszy();
	}
	return 0;
}