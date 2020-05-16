#include <SFML/Graphics.hpp>
//#include "Game.h"
#include "Menu.h"
#include <time.h>
#include <sstream>


int main(){
	sf::RenderWindow window(sf::VideoMode(400,400),"Minesweeper!");
	Menu menu(window.getSize().x, window.getSize().y);
	menu.Draw(window);
	return 0;
}
