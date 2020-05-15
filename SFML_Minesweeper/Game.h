#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Game
{
	const int w = 32;//Ширина клетки

	sf::Font font;
	//Vector2i pos = Mouse::getPosition(app);
	//int x = pos.x / w;
	//int y = pos.y / w;
public:
	Game(RenderWindow& menu, float width, float height);
	//void Draw();
};

