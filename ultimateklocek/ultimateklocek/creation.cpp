#include "creation.h"
#include <sfml\graphics.hpp>


void creation(sf::RectangleShape& haha, sf::RectangleShape& oof, sf::RectangleShape& p, sf::RectangleShape& o, sf::RectangleShape& s, sf::RectangleShape& tetris, sf::RectangleShape& p0, sf::RectangleShape& p2, sf::RectangleShape& p3, sf::Texture& hahatexture, sf::Texture& ooftexture, sf::Texture& stexture, sf::Texture& tetristexture, sf::Texture& p0texture, sf::Texture& p2texture, sf::Texture& p3texture, sf::RectangleShape& enterr, sf::Texture& enterrtexture)
{


	haha.setOrigin(300.0f, 160.0f);
	hahatexture.loadFromFile("textury/haha.png");
	haha.setTexture(&hahatexture);
	haha.setPosition(3000, 3000);


	oof.setOrigin(87.0f, 37.0f);
	ooftexture.loadFromFile("textury/oof.png");
	oof.setTexture(&ooftexture);
	oof.setPosition(3000, 3000);


	stexture.loadFromFile("textury/score.png");
	s.setTexture(&stexture);
	s.setPosition(700, 100);


	tetris.setOrigin(300.0f, 100.0f);
	tetristexture.loadFromFile("textury/tetris.png");
	tetris.setTexture(&tetristexture);


	p0.setOrigin(87.0f, 37.0f);
	p0texture.loadFromFile("textury/play.png");
	p0.setTexture(&p0texture);

	p2.setOrigin(87.0f, 37.0f);
	p2texture.loadFromFile("textury/how.png");
	p2.setTexture(&p2texture);

	p3.setOrigin(87.0f, 37.0f);
	p3texture.loadFromFile("textury/quit.png");
	p3.setTexture(&p3texture);


	tetris.setPosition(600, 300);
	p0.setPosition(600, 600);
	p2.setPosition(600, 700);
	p3.setPosition(600, 800);



	enterrtexture.loadFromFile("textury/enter.png");
	enterr.setTexture(&enterrtexture);
	enterr.setPosition(730, 450);

	p.setFillColor(sf::Color(199, 255, 199));
	o.setPosition(20, 20);
	p.setPosition(30, 30);

}

void howtoplay(sf::RectangleShape& haha, sf::RectangleShape& oof, sf::RectangleShape& tetris, sf::RectangleShape& p0, sf::RectangleShape& p2, sf::RectangleShape& p3)
{
	tetris.setPosition(3000, 3000);
	p0.setPosition(3000, 3000);
	p2.setPosition(3000, 3000);
	p3.setPosition(3000, 3000);
	haha.setPosition(600, 475);
	oof.setPosition(600, 750);
}
void back(sf::RectangleShape& haha, sf::RectangleShape& oof, sf::RectangleShape& tetris, sf::RectangleShape& p0, sf::RectangleShape& p2, sf::RectangleShape& p3)
{

	tetris.setPosition(600, 300);
	p0.setPosition(600, 600);
	p2.setPosition(600, 700);
	p3.setPosition(600, 800);
	haha.setPosition(3000, 3000);
	oof.setPosition(3000, 3000);

}

void gameizon(sf::RenderWindow &window, sf::RectangleShape& haha, sf::RectangleShape& oof, sf::RectangleShape& tetris, sf::RectangleShape& p0, sf::RectangleShape& p2, sf::RectangleShape& p3)
{

	window.clear(sf::Color(255, 199, 227));
	window.draw(haha);
	window.draw(tetris);
	window.draw(p0);
	window.draw(p2);
	window.draw(p3);
	window.draw(oof);
	window.display();
}