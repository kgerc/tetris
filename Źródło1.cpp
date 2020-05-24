#include <iostream>
#include "klocek.h"
#include "plansza.h"
using namespace std;

int main()
{
	int x;
	Plansza p1(20);
	p1.Generator_Klockow(1, 1, 6, 2);
	p1.Generator_Planszy();
	cout << "kierunek:";
	cin >> x;
	switch (x)
	{
	case 1:
		{	
			p1.Czyszczenie_klockow(1, 1, 6, 2);
			p1.Generator_Klockow(2, 1, 6, 2);
		}
	}
	system("cls");
	p1.Generator_Planszy();
	return 0;
}