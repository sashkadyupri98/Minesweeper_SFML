#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#define MAX_NUMBER_OF_ITEMS 2
class OverGame
{
public:
	OverGame(float width, float height);
	void Draw(RenderWindow& window);
private:
    int selectedItemIndex;
    Font font;
    Vector2u WindowSize;
    Text menu[MAX_NUMBER_OF_ITEMS];
};

