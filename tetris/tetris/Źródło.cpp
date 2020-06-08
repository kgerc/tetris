#include <sfml\graphics.hpp>
#include <iostream>
#include "creation.h"
#include "menu.h"
#include "game.h"


int main()
{
	bool gameison = 0;
	bool lego = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 950), "Tetris crash testy", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape haha(sf::Vector2f(600.0f, 321.0f));
	sf::RectangleShape oof(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape k(sf::Vector2f(50.0f, 50.0f));
	sf::RectangleShape p(sf::Vector2f(500.0f, 900.0f));
	sf::RectangleShape o(sf::Vector2f(520.0f, 920.0f));
	sf::RectangleShape s(sf::Vector2f(300.0f, 120.0f));
	sf::RectangleShape tetris(sf::Vector2f(600.0f, 200.0f));
	sf::RectangleShape p1(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape p2(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape p3(sf::Vector2f(175.0f, 75.0f));
	sf::RectangleShape enterr(sf::Vector2f(250.0f, 50.0f));
	sf::Texture enterrtexture;
	sf::Texture hahatexture;
	sf::Texture ooftexture;
	sf::Texture stexture;
	sf::Texture tetristexture;
	sf::Texture p1texture;
	sf::Texture p2texture;
	sf::Texture p3texture;
	sf::Texture cubetexture;
	
	creation(haha, oof, k, p, o, s, tetris, p1, p2, p3, hahatexture, ooftexture, stexture, tetristexture, p1texture, p2texture, p3texture, cubetexture, enterr, enterrtexture);

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
				window.clear(sf::Color(255, 199, 227));
				window.draw(haha);
				window.draw(tetris);
				window.draw(p1);
				window.draw(p2);
				window.draw(p3);
				window.draw(oof);

				window.display();

				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						sf::Vector2i mousepos = sf::Mouse::getPosition(window);
						sf::Vector2f p1pos = p1.getPosition();

						if (p1pos.x == 600 && p1pos.y == 600)
						{
							if (mousepos.x >= 513 && mousepos.x <= 687 && mousepos.y >= 563 && mousepos.y <= 637)
							{
								gameison = 1;
							}


							if (mousepos.x >= 513 && mousepos.x <= 687 && mousepos.y >= 663 && mousepos.y <= 737)
							{
								howtoplay(haha, oof, tetris, p1, p2, p3);

							}
							if (mousepos.x >= 513 && mousepos.x <= 687 && mousepos.y >= 763 && mousepos.y <= 837)
							{
								window.close();
							}
						}
						if (p1pos.x == 3000 && p1pos.y == 3000)
						{
							if (mousepos.x >= 513 && mousepos.x <= 687 && mousepos.y >= 713 && mousepos.y <= 787)
							{
								back(haha, oof, tetris, p1, p2, p3);
							}
						}
					}
				}
			}
			else
			{
				if (lego == 0)
				{
					window.clear(sf::Color(199, 255, 227));
					window.draw(o);
					window.draw(p);
					window.draw(k);
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
					window.clear(sf::Color(199, 255, 227));
					window.draw(o);
					window.draw(p);
					window.draw(k);
					window.draw(s);
					scorr(window);
					game(window);
					window.display();


				}
			}
		}

	}


	return 0;
}

