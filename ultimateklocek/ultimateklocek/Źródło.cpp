#include <SFML\Graphics.hpp>
#include "plansza.h"
#include <iostream>
#include "creation.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 950), "Tetris crash testy", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape haha(sf::Vector2f(600.0f, 321.0f));
	sf::RectangleShape oof(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape p(sf::Vector2f(500.0f, 900.0f));
	sf::RectangleShape o(sf::Vector2f(520.0f, 920.0f));
	sf::RectangleShape s(sf::Vector2f(300.0f, 120.0f));
	sf::RectangleShape tetris(sf::Vector2f(600.0f, 200.0f));
	sf::RectangleShape p0(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape p2(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape p3(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape enterr(sf::Vector2f(250.0f, 50.0f));
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
			M[i].position = sf::Vector2f(-20 + 50 * p, -20 + 50 * d);
			M[i].color = sf::Color(0, 0, 0);
			i++;
		}
	}


	int x1 = -2, y1 = 3, r_klocka = 1, rotacja = 0, x;
	Plansza p1(20);
	p1.Generator_Klockow(x1, y1, r_klocka, rotacja);
	p1.Generator_Planszy();



	bool gameison = 0;
	bool lego = 0;

	while (window.isOpen())
	{
		window.setKeyRepeatEnabled(false);
		sf::Event event;

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


						if (p0pos.x == 600 && p0pos.y == 600)
						{
							if (mousepos.x >= 513 && mousepos.x <= 687 && mousepos.y >= 563 && mousepos.y <= 637)
							{
								gameison = 1;
							}


							if (mousepos.x >= 513 && mousepos.x <= 687 && mousepos.y >= 663 && mousepos.y <= 737)
							{
								howtoplay(haha, oof, tetris, p0, p2, p3);

							}
							if (mousepos.x >= 513 && mousepos.x <= 687 && mousepos.y >= 763 && mousepos.y <= 837)
							{
								window.close();
							}
						}
						if (p0pos.x == 3000 && p0pos.y == 3000)
						{
							if (mousepos.x >= 513 && mousepos.x <= 687 && mousepos.y >= 713 && mousepos.y <= 787)
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
						}

					}
				}
				else
				{
					window.clear(sf::Color(255, 199, 227));
					window.draw(o);
					window.draw(p);
					window.draw(s);
					scorr(window);

					if (event.type == sf::Event::KeyPressed)
					{
						if (event.key.code == sf::Keyboard::Down)
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
									std::cout << "GAME OVER";
									exit(0);
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
							p1.Czyszczenie_klockow(x1,
								y1, r_klocka, rotacja);
							rotacja = p1.RotujKlocka1(rotacja);
							y1 = p1.RotujKlocka2(x1, y1, r_klocka, rotacja);
							x1 = p1.RotujKlocka3(x1, y1, r_klocka, rotacja);
						}
					}
					system("cls");

					p1.Generator_Planszy();
					p1.Generujklocka(window, M);


					window.display();

				}
			}
		}
	
			
	}
	return 0;
}