#include <iostream>
#include "klocek.h"
#include "plansza.h"
using namespace std;

int main()
{
	//Inicjalizacja planszy i pierwszego klocka
	int x1 = -1, y1 = 3, r_klocka = 1, rotacja = 1;
	Plansza p1(20);
	p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
	p1.Generator_Planszy();
	//Giera tutaj
	for(;;)
	{
		//1-dó³
		//2-prawo
		//3-lewo
		//4-rotacja
		char x;
		x = _getch();
				switch (x)
				{
				case 's':
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
						p1.Czy_usuwac_linie();
						if (p1.KoniecGry() == true)
						{
							cout << "GAME OVER";
							exit(0);
						}
						r_klocka = p1.GetRand();
						x1 = p1.Pozycja_poczatkowa_x(r_klocka, rotacja);
						y1 = p1.Pozycja_poczatkowa_y(r_klocka, rotacja);
						p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
					}

				}
				break;
				case 'd':
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

				case 'a':
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
				case 'w':
				{
						//zmienne na wypadek jak nie mozna rotowac
						int x2 = x1;
						int y2 = y1;
						int r_klocka2 = r_klocka;
						int rotacja2 = rotacja;
						//
						p1.Czyszczenie_klockow(x1, y1, r_klocka, rotacja);
						rotacja = p1.RotujKlocka1(rotacja);
						y1 = p1.RotujKlocka2(x1, y1, r_klocka, rotacja);
						x1 = p1.RotujKlocka3(x1, y1, r_klocka, rotacja);
						if (p1.czy_mozna_rotowac(x1, y1, r_klocka, rotacja))
						{
							p1.RotujKlocka4(x1, y1, r_klocka, rotacja);
						}
						else
						{
							p1.Generator_Klockow(x2, y2, r_klocka2, rotacja2);
							//przypisanie zmiennym glownym wartosci zmiennych pomocniczych dla dalszych ruchów
							x1 = x2;
							y1 = y2;
							r_klocka = r_klocka2;
							rotacja = rotacja2;
							//
						}
				}
				break;
				default:
				{
					exit(0);
				}
	
				}
				system("cls");
				p1.Generator_Planszy();
	}
	return 0;
}