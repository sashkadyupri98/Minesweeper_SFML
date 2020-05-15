#include "Game.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
using namespace sf;

Game::Game(RenderWindow& menu, float width, float height) {
	menu.close();
	//��������� ��������� �����
	srand(time(0));

	RenderWindow window(VideoMode(width, height), "Minesweeper!");
	int mine = 0;
	int gridLogic[12][12];
	int gridView[12][12];

	font.loadFromFile("sansation.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::Black);

	//�������� �������� � �������� �������
	Texture t;
	t.loadFromFile("images/tiles.jpg");
	Sprite s(t);

	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			gridView[i][j] = 10;
			if (rand() % 5 == 0) {
				gridLogic[i][j] = 9;
				mine++;
			}
			else gridLogic[i][j] = 0;
		}
	//������� ��� ������ ������ ������
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			int n = 0;
			if (gridLogic[i][j] == 9) continue;
			if (gridLogic[i + 1][j] == 9) n++;
			if (gridLogic[i][j + 1] == 9) n++;
			if (gridLogic[i - 1][j] == 9) n++;
			if (gridLogic[i][j - 1] == 9) n++;
			if (gridLogic[i + 1][j + 1] == 9) n++;
			if (gridLogic[i - 1][j - 1] == 9) n++;
			if (gridLogic[i - 1][j + 1] == 9) n++;
			if (gridLogic[i + 1][j - 1] == 9) n++;
			gridLogic[i][j] = n;
		}

	while (window.isOpen())
	{
		//�������� ���������� ���� ������������ ���� ������ ����������
		Vector2i pos = Mouse::getPosition(window);
		int x = pos.x / w;
		int y = pos.y / w;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			//���� ������ ������ ����?
			if (e.type == Event::MouseButtonPressed)
				//���� ��� - ����� ������ ����, �� ��������� ������
				if (e.key.code == Mouse::Left) gridView[x][y] = gridLogic[x][y];
			//���� ��� � ������ ������ ����, �� ���������� ������
				else if (e.key.code == Mouse::Right) {
					gridView[x][y] = 11;
					mine--;
				}
		}

		//������������� ����� ���
		window.clear(Color::White);

		std::ostringstream ss;    // #include <sstream>
		ss << mine;
		text.setString("Mines: " + ss.str());
		text.setPosition(0, 0);
		window.draw(text);

		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++)
			{
				if (gridView[x][y] == 9) gridView[i][j] = gridLogic[i][j];
				//�������� �� ������� ������ ��� ��������� ��������
				s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
				//������������� ��� �������� ��������
				s.setPosition(i * w, j * w);
				//� � ������������
				window.draw(s);
			}
		//���������� ��� ���������� �� ������
		window.display();
	}
}

