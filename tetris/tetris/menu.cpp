#include "menu.h"
#include <sfml\graphics.hpp>


void howtoplay(sf::RectangleShape& haha, sf::RectangleShape& oof, sf::RectangleShape& tetris, sf::RectangleShape& p1, sf::RectangleShape& p2, sf::RectangleShape& p3)
{
	tetris.setPosition(3000, 3000);
	p1.setPosition(3000, 3000);
	p2.setPosition(3000, 3000);
	p3.setPosition(3000, 3000);
	haha.setPosition(600, 475);
	oof.setPosition(600, 750);
}
void back(sf::RectangleShape& haha, sf::RectangleShape& oof, sf::RectangleShape& tetris, sf::RectangleShape& p1, sf::RectangleShape& p2, sf::RectangleShape& p3)
{

	tetris.setPosition(600, 300);
	p1.setPosition(600, 600);
	p2.setPosition(600, 700);
	p3.setPosition(600, 800);
	haha.setPosition(3000, 3000);
	oof.setPosition(3000, 3000);

}

