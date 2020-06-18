#include <SFML\Graphics.hpp>
#include "plansza.h"
#include "creation.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 740), "Tetris crash testy", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape haha(sf::Vector2f(600.0f, 321.0f));
	sf::RectangleShape oof(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape p(sf::Vector2f(400.0f, 720.0f));
	sf::RectangleShape o(sf::Vector2f(410.0f, 730.0f));
	sf::RectangleShape s(sf::Vector2f(300.0f, 120.0f));
	sf::RectangleShape tetris(sf::Vector2f(600.0f, 200.0f));
	sf::RectangleShape p0(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape p2(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape p3(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape enterr(sf::Vector2f(250.0f, 150.0f));
	sf::Texture enterrtexture;
	sf::Texture hahatexture;
	sf::Texture ooftexture;
	sf::Texture stexture;
	sf::Texture tetristexture;
	sf::Texture p0texture;
	sf::Texture p2texture;
	sf::Texture p3texture;

	creation(haha, oof, p, o, s, tetris, p0, p2, p3, hahatexture, ooftexture, stexture, tetristexture, p0texture, p2texture, p3texture, enterr, enterrtexture);

	sf::VertexArray M(sf::PrimitiveType::Points, 240);

	unsigned int i = 0;
	for (unsigned int d = 0; d < 20; d++)
	{
		for (unsigned int p = 0; p < 12; p++)
		{
			M[i].position = sf::Vector2f(-30 + 40 * p, -30 + 40 * d);
			M[i].color = sf::Color(0, 0, 0);
			i++;
		}
	}


	int x1 = -2, y1 = 3, r_klocka = 1, rotacja = 0, x;
	Plansza p1(20);
	p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
	p1.Generator_Planszy();

	sf::Clock clock;
	sf::Time time;
	float czas;
	sf::Event event;

	bool lose = 0;

	bool gameison = 0;
	bool lego = 0;
	window.setKeyRepeatEnabled(true);

	while (window.isOpen())
	{
		window.setActive(true);
		if (lose == 0)
		{
			if (lego == 1)
			{
				float scrr;
				window.clear(sf::Color(255, 199, 227));
				window.draw(o);
				window.draw(p);
				window.draw(s);
				scrr = scorr(window);
				time = clock.getElapsedTime();
				czas = time.asSeconds() + scrr*0.001f;
				//std::cout << czas;

				if (czas > 1.0f)
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
							lose = 1;
						}
						r_klocka = p1.GetRand();
						x1 = p1.Pozycja_poczatkowa_x(r_klocka, rotacja);
						y1 = p1.Pozycja_poczatkowa_y(r_klocka, rotacja);
						p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
					}
					clock.restart();
				}
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();

					if (event.type == sf::Event::KeyPressed)
					{
						if (event.key.code == sf::Keyboard::Down)
						{
							clock.restart();

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
									lose = 1;
								}
								r_klocka = p1.GetRand();
								x1 = p1.Pozycja_poczatkowa_x(r_klocka, rotacja);
								y1 = p1.Pozycja_poczatkowa_y(r_klocka, rotacja);
								p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
							}

						}
						if (event.key.code == sf::Keyboard::Right)
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
						if (event.key.code == sf::Keyboard::Left)
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
						if (event.key.code == sf::Keyboard::Up)
						{
							window.setKeyRepeatEnabled(false);
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
					}
					if (event.type == sf::Event::KeyReleased)
					{
						if (event.key.code == sf::Keyboard::Up)
						{
							window.setKeyRepeatEnabled(true);
						}

					}
				}
				system("cls");

				p1.Generator_Planszy();
				p1.Generujklocka(window, M);

				window.display();

			}

			else
			{
				while (window.pollEvent(event))
				{

					if (event.type == sf::Event::Closed)
						window.close();

					if (gameison == 0)
					{

						gameizon(window, haha, oof, tetris, p0, p2, p3);


						if (event.type == sf::Event::MouseButtonPressed)
						{
							if (event.mouseButton.button == sf::Mouse::Left)
							{
								sf::Vector2i mousepos = sf::Mouse::getPosition(window);
								sf::Vector2f p0pos = p0.getPosition();


								if (p0pos.x == 450 && p0pos.y == 400)
								{
									if (mousepos.x >= 363 && mousepos.x <= 537 && mousepos.y >= 363 && mousepos.y <= 437)
									{
										gameison = 1;
									}


									if (mousepos.x >= 363 && mousepos.x <= 537 && mousepos.y >= 463 && mousepos.y <= 537)
									{
										howtoplay(haha, oof, tetris, p0, p2, p3);

									}
									if (mousepos.x >= 363 && mousepos.x <= 537 && mousepos.y >= 563 && mousepos.y <= 637)
									{
										window.close();
										return 0;
									}
								}
								if (p0pos.x == 3000 && p0pos.y == 3000)
								{
									if (mousepos.x >= 363 && mousepos.x <= 537 && mousepos.y >= 563 && mousepos.y <= 637)
									{
										back(haha, oof, tetris, p0, p2, p3);
									}
								}
							}
						}
					}

					else
					{
						if (lego == 0)
						{

							window.clear(sf::Color(255, 199, 227));
							window.draw(o);
							window.draw(p);
							window.draw(s);
							window.draw(enterr);

							window.display();

							if (event.type == sf::Event::KeyPressed)
							{
								if (event.key.code == sf::Keyboard::Enter)
								{
									lego = 1;
									clock.restart();
								}

							}
						}

					}
				}
			}
		}
		else
		{

			gamerover(window);
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Enter)
					{
						exit(0);
					}
				}
			}

		}
			
	}
	return 0;
}