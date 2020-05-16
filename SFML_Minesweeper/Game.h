#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#define LENGHT 10
#define WIDTH 10
#define BOMBS 4

struct poz
{
	int row;
	int column;
};
class Game
{
	const int w = 32;//Ширина клетки
	int gridLogic[LENGHT + 1][WIDTH + 1];
	int gridView[LENGHT + 1][WIDTH + 1];
	poz tail[10000];
	int ltail, excttail, firstMove=0, bombsFound, countBombsFound, countCheckFoundBombs, countOpenCell;
	sf::Font font;
	int countBomb =BOMBS;
public:
	void initialisationGridView();
	void bombsInitialisation(int a, int b);
	void numberGenerate();
	void verification0(int i, int j);
	void moveFirst(int i, int j);
	int checkBombsFoundLogic(int i, int j);
	bool checkOpenAllCell(int countOpenCell);
	Game(RenderWindow& menu, float width, float height);
	//void Draw();
};

