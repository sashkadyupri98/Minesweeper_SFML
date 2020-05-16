#include "Game.h"
//#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <sstream>
using namespace sf;


void Game::initialisationGridView() {
	for (int i = 1; i <= LENGHT; i++) {
		for (int j = 1; j <= WIDTH; j++) {
			gridView[i][j] = 10;
		}
	}
}
void Game::bombsInitialisation(int a, int b) {
	for (int i = 1; i <= BOMBS; i++) {
		int x = rand() % LENGHT + 1;
		int y = rand() % WIDTH + 1;
		if (x == a && y == b) {
			int x = rand() % LENGHT + 1;
			int y = rand() % WIDTH + 1;
		}
		gridLogic[x][y] = 9;
	}
}
void Game::numberGenerate() {
	for (int i = 1; i <= LENGHT; i++) {
		for (int j = 1; j <= WIDTH; j++) {
			if (gridLogic[i][j] != 9) {
				int noBombs = 0;
				if (gridLogic[i + 1][j] == 9) noBombs++;
				if (gridLogic[i][j + 1] == 9) noBombs++;
				if (gridLogic[i - 1][j] == 9) noBombs++;
				if (gridLogic[i][j - 1] == 9) noBombs++;
				if (gridLogic[i + 1][j + 1] == 9) noBombs++;
				if (gridLogic[i - 1][j - 1] == 9) noBombs++;
				if (gridLogic[i - 1][j + 1] == 9) noBombs++;
				if (gridLogic[i + 1][j - 1] == 9) noBombs++;
				gridLogic[i][j] = noBombs;
			}
		}
	}
}
void Game::verification0(int i, int j) {
	gridView[i][j] = 0;
	if (gridLogic[i - 1][j - 1] == 0 && i - 1 > 0 && i - 1 <= LENGHT && j - 1 > 0 && j - 1 <= WIDTH)
	{
		tail[ltail].column = i - 1;
		tail[ltail].row = j-1;
		ltail++;
	}
	if (gridLogic[i - 1][j] == 0 && i - 1 > 0 && i - 1 <= LENGHT && j > 0 && j <= WIDTH)
	{
		tail[ltail].column = i - 1;
		tail[ltail].row = j;
		ltail++;
	}
	if (gridLogic[i - 1][j+1] == 0 && i - 1 > 0 && i - 1 <= LENGHT && j+1 > 0 && j+1 <= WIDTH)
	{
		tail[ltail].column = i - 1;
		tail[ltail].row = j+1;
		ltail++;
	}
	if (gridLogic[i][j-1] == 0 && i > 0 && i <= LENGHT && j-1 > 0 && j-1 <= WIDTH)
	{
		tail[ltail].column = i;
		tail[ltail].row = j-1;
		ltail++;
	}
	if (gridLogic[i][j+1] == 0 && i > 0 && i <= LENGHT && j + 1 > 0 && j + 1 <= WIDTH)
	{
		tail[ltail].column = i;
		tail[ltail].row = j + 1;
		ltail++;
	}
	if (gridLogic[i+1][j - 1] == 0 && i+1 > 0 && i+1 <= LENGHT && j - 1 > 0 && j - 1 <= WIDTH)
	{
		tail[ltail].column = i+1;
		tail[ltail].row = j - 1;
		ltail++;
	}
	if (gridLogic[i + 1][j] == 0 && i + 1 > 0 && i + 1 <= LENGHT && j > 0 && j <= WIDTH)
	{
		tail[ltail].column = i + 1;
		tail[ltail].row = j;
		ltail++;
	}
	if (gridLogic[i + 1][j + 1] == 0 && i + 1 > 0 && i + 1 <= LENGHT && j + 1 > 0 && j + 1 <= WIDTH)
	{
		tail[ltail].column = i + 1;
		tail[ltail].row = j + 1;
		ltail++;
	}
}
void Game::moveFirst(int i, int j) {
	if (gridLogic[i][j] == 0) {
		gridView[i][j] = 0;
		verification0(i,j);
		while (excttail < ltail)
		{
			gridView[tail[excttail].column][tail[excttail].row] = 0;
			excttail++;
		}
	}
	else {
		gridView[i][j] = gridLogic[i][j];
	}
	if (gridLogic[i-1][j-1]!=9 && i - 1 > 0 && i - 1 <= LENGHT && j - 1 > 0 && j - 1 <= WIDTH) {
		if (gridLogic[i - 1][j - 1] == 0) {
			gridView[i - 1][j - 1] = 0;
			verification0(i - 1, j - 1);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i-1][j-1] = gridLogic[i-1][j-1];
		}
	}

	if (gridLogic[i - 1][j] != 9 && i - 1 > 0 && i - 1 <= LENGHT && j > 0 && j <= WIDTH) {
		if (gridLogic[i - 1][j] == 0) {
			gridView[i - 1][j] = 0;
			verification0(i - 1, j);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i - 1][j] = gridLogic[i - 1][j];
		}
	}
	if (gridLogic[i - 1][j + 1] != 9 && i - 1 > 0 && i - 1 <= LENGHT && j + 1 > 0 && j + 1 <= WIDTH) {
		if (gridLogic[i - 1][j + 1] == 0) {
			gridView[i - 1][j + 1] = 0;
			verification0(i - 1, j + 1);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i - 1][j + 1] = gridLogic[i - 1][j + 1];
		}
	}
	if (gridLogic[i][j - 1] != 9 && i > 0 && i <= LENGHT && j - 1 > 0 && j - 1 <= WIDTH) {
		if (gridLogic[i][j - 1] == 0) {
			gridView[i][j - 1] = 0;
			verification0(i, j - 1);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i][j - 1] = gridLogic[i][j - 1];
		}
	}
	if (gridLogic[i][j + 1] != 9 && i > 0 && i <= LENGHT && j + 1 > 0 && j + 1 <= WIDTH) {
		if (gridLogic[i][j + 1] == 0) {
			gridView[i][j + 1] = 0;
			verification0(i, j + 1);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i][j + 1] = gridLogic[i][j + 1];
		}
	}
	if (gridLogic[i + 1][j - 1] != 9 && i + 1 > 0 && i + 1 <= LENGHT && j - 1 > 0 && j - 1 <= WIDTH) {
		if (gridLogic[i + 1][j - 1] == 0) {
			gridView[i + 1][j - 1] = 0;
			verification0(i + 1, j - 1);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i + 1][j - 1] = gridLogic[i + 1][j - 1];
		}
	}
	if (gridLogic[i + 1][j] != 9 && i + 1 > 0 && i + 1 <= LENGHT && j > 0 && j <= WIDTH) {
		if (gridLogic[i + 1][j] == 0) {
			gridView[i + 1][j] = 0;
			verification0(i + 1, j);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i + 1][j] = gridLogic[i + 1][j];
		}
	}
	if (gridLogic[i + 1][j + 1] != 9 && i + 1 > 0 && i + 1 <= LENGHT && j + 1 > 0 && j + 1 <= WIDTH) {
		if (gridLogic[i + 1][j + 1] == 0) {
			gridView[i + 1][j + 1] = 0;
			verification0(i + 1, j + 1);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i + 1][j + 1] = gridLogic[i + 1][j + 1];
		}
	}
	if (gridLogic[i - 1][j + 2] != 9 && i - 1 > 0 && i - 1 <= LENGHT && j + 2 > 0 && j + 2 <= WIDTH) {
		if (gridLogic[i - 1][j + 2] == 0) {
			gridView[i - 1][j + 2] = 0;
			verification0(i - 1, j + 2);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i - 1][j + 2] = gridLogic[i - 1][j + 2];
		}
	}
	if (gridLogic[i][j + 2] != 9 && i > 0 && i <= LENGHT && j + 2 > 0 && j + 2 <= WIDTH) {
		if (gridLogic[i][j + 2] == 0) {
			gridView[i][j + 2] = 0;
			verification0(i, j + 2);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i][j + 2] = gridLogic[i][j + 2];
		}
	}
	if (gridLogic[i + 1][j + 2] != 9 && i + 1 > 0 && i + 1 <= LENGHT && j + 2 > 0 && j + 2 <= WIDTH) {
		if (gridLogic[i + 2][j + 2] == 0) {
			gridView[i + 1][j + 2] = 0;
			verification0(i + 1, j + 2);
			while (excttail < ltail)
			{
				gridView[tail[excttail].column][tail[excttail].row] = 0;
				excttail++;
			}
		}
		else
		{
			gridView[i + 1][j + 2] = gridLogic[i + 1][j + 2];
		}
	}
}
int Game::checkBombsFoundLogic(int i, int j) {
	if (gridLogic[i][j]==9) {
		countCheckFoundBombs++;
	}
	return countCheckFoundBombs;
}
bool Game::checkOpenAllCell(int countOpenCell) {
	for (int i = 1; i <= LENGHT; i++)
	{
		for (int j = 1; j <= WIDTH; j++)
		{
			if (gridView[i][j] < 10) {
				countOpenCell++;
			}
		}
	}
	if (countOpenCell == 100) {
		return true;
	}
	else return false;
}
Game::Game(RenderWindow& menu, float width, float height) {
	menu.close();
	//Генератор случайных чисел
	//srand(time(0));

	RenderWindow window(VideoMode(width, height), "Minesweeper!");
	excttail = 0;
	ltail = 0;
	bombsFound = 0;
	countBombsFound = BOMBS;
	countBomb = BOMBS;
	countCheckFoundBombs=0;
	countOpenCell = 0;
	countFlag = 0;

	font.loadFromFile("sansation.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::Black);
	Text gameover("", font, 40);
	gameover.setFillColor(Color::Red);

	//Загрузка текстуры и создание спрайта
	Texture t;
	t.loadFromFile("images/tiles.jpg");
	Sprite s(t);
	initialisationGridView();
	

	while (window.isOpen())
	{
		
		Vector2i pos = Mouse::getPosition(window);
		int x = pos.x / w;
		int y = pos.y / w;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			//Была нажата кнопка мыши…?
			if (e.type == Event::MouseButtonPressed)
				//Если это - левая кнопка мыши, то открываем клетку
				if (e.key.code == Mouse::Left) {
					if (firstMove == 0) {
						bombsInitialisation(x, y);
						numberGenerate();
						moveFirst(x,y);
						firstMove = 1;
					}
					else if (gridView[x][y] == 0)
					{
						verification0(x,y);
						while (excttail < ltail)
						{
							gridView[tail[excttail].column][tail[excttail].row] = 0;
							excttail++;
						}
					}
					else {
						gridView[x][y] = gridLogic[x][y];
					}
				}
			//Если это – правая кнопка мыши, то отображаем флажок
				else if (e.key.code == Mouse::Right) {
					
					if (gridView[x][y] == 11) {
						gridView[x][y] = 10;
						countFlag--;
						countBombsFound = countBombsFound + 1;
					}
					else if(gridView[x][y] > 9 && countFlag < countBomb)
					{ 
							gridView[x][y] = 11;
							countFlag++;
							countBombsFound = countBombsFound - 1;
						
					}
				
					if (gridLogic[x][y] == 9) {
						bombsFound++;
					}
					
				}
		}

	

		if (bombsFound == BOMBS) {
			gameover.setString("Win");
			gameover.setPosition(170, 150);
			window.draw(gameover);
			window.display();
		}
		else
		{
			//Устанавливаем белый фон
			window.clear(Color::White);
			std::ostringstream ss;    // #include <sstream>
			ss << countBombsFound;
			text.setString("Flags: " + ss.str());
			text.setPosition(0, 0);
			window.draw(text);
			for (int i = 1; i <= LENGHT; i++) 
			{
				for (int j = 1; j <= WIDTH; j++) 
				{
					if (gridView[x][y] == 9) {
						gridView[i][j] = gridLogic[i][j];
					}
					s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
					//Устанавливаем его заданную позицию…
					s.setPosition(i * w, j * w);
					//… и отрисовываем
					window.draw(s);
				}
			}
			if (checkOpenAllCell(countOpenCell) == true) {
				//window.clear(Color::White);
				gameover.setString("Game Over");
				gameover.setPosition(100, 150);
				window.draw(gameover);
			}
			window.display();
		}
		
	}
}

