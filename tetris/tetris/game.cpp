#include <sfml\graphics.hpp>
#include <iostream>
#include "game.h"

void game(sf::RenderWindow &window)
{
	sf::VertexArray M(sf::PrimitiveType::Points, 240);
	unsigned int i = 0;
	for (unsigned int p = 0; p < 12; p++)
	{
		for (unsigned int d = 0; d < 20; d++)
		{
			M[i].position = sf::Vector2f(-20 + 50 * p, -20 + 50 * d);
			M[i].color = sf::Color(0, 0, 0);
			i++;
		}
	}
	window.draw(M);

}

void scorr(sf::RenderWindow& window)
{

	int scr = 0;
	std::string score = std::to_string(scr);
	if (scr < 10)
		score = "000" + score;
	else if(scr<100)
		score = "00" + score;
	else if (scr < 1000)
		score = "0" + score;

	sf::Font czcionka;
	czcionka.loadFromFile("font/scorefont.ttf");
	sf::Text scre(score, czcionka);
	scre.setFillColor(sf::Color(217, 141, 255));
	scre.setCharacterSize(100);
	scre.setPosition(710, 250);


	window.draw(scre);
}