#include <sfml\graphics.hpp>
#include <iostream>


int main()
{
	int gameison = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 950), "Tetris crash testy", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape haha(sf::Vector2f(600.0f, 321.0f));
	haha.setOrigin(300.0f, 160.0f);
	sf::Texture hahatexture;
	hahatexture.loadFromFile("textury/haha.png");
	haha.setTexture(&hahatexture);
	haha.setPosition(3000, 3000);

	sf::RectangleShape oof(sf::Vector2f(175.0f, 75.0f));
	oof.setOrigin(87.0f, 37.0f);
	sf::Texture ooftexture;
	ooftexture.loadFromFile("textury/oof.png");
	oof.setTexture(&ooftexture);
	oof.setPosition(3000, 3000);

	sf::RectangleShape k(sf::Vector2f(50.0f, 50.0f));
	sf::RectangleShape p(sf::Vector2f(500.0f, 900.0f));
	sf::RectangleShape o(sf::Vector2f(520.0f, 920.0f));
	sf::RectangleShape s(sf::Vector2f(300.0f, 120.0f));

	sf::Texture stexture;
	stexture.loadFromFile("textury/score.png");
	s.setTexture(&stexture);

	sf::RectangleShape tetris(sf::Vector2f(600.0f, 200.0f));
	tetris.setOrigin(300.0f, 100.0f);
	sf::RectangleShape p1(sf::Vector2f(175.0f, 75.0f));
	p1.setOrigin(87.0f, 37.0f);
	sf::RectangleShape p2(sf::Vector2f(175.0f, 75.0f));
	p2.setOrigin(87.0f, 37.0f);
	sf::RectangleShape p3(sf::Vector2f(175.0f, 75.0f));
	p3.setOrigin(87.0f, 37.0f);

	tetris.setPosition(600, 300);
	p1.setPosition(600, 600);
	p2.setPosition(600, 700);
	p3.setPosition(600, 800);

	sf::Texture tetristexture;
	tetristexture.loadFromFile("textury/tetris.png");
	tetris.setTexture(&tetristexture);

	sf::Texture p1texture;
	p1texture.loadFromFile("textury/play.png");
	p1.setTexture(&p1texture);

	sf::Texture p2texture;
	p2texture.loadFromFile("textury/how.png");
	p2.setTexture(&p2texture);

	sf::Texture p3texture;
	p3texture.loadFromFile("textury/quit.png");
	p3.setTexture(&p3texture);

	p.setFillColor(sf::Color(199,255,199));
	o.setPosition(20, 20);
	p.setPosition(30, 30);
	k.setOrigin(25.0f, 25.0f);
	k.setPosition(360, 320);
	s.setPosition(700, 100);
	sf::Texture cubetexture;
	cubetexture.loadFromFile("textury/cube.png");
	k.setTexture(&cubetexture);


	while (window.isOpen())
	{
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
								std::cout << "elo";
								tetris.setPosition(3000, 3000);
								p1.setPosition(3000, 3000);
								p2.setPosition(3000, 3000);
								p3.setPosition(3000, 3000);
								haha.setPosition(600, 475);
								oof.setPosition(600, 750);


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
								std::cout << "elo";
								tetris.setPosition(600, 300);
								p1.setPosition(600, 600);
								p2.setPosition(600, 700);
								p3.setPosition(600, 800);
								haha.setPosition(3000, 3000);
								oof.setPosition(3000, 3000);
							}
						}
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
				window.display();

			}
		}

/*		window.clear(sf::Color(255,199,227));
		window.draw(haha);
		window.draw(tetris);
		window.draw(p1);
		window.draw(p2);
		window.draw(p3);
		window.draw(oof);

		window.display();
	*/	
	}


	return 0;
}

