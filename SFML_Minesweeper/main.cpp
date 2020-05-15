#include <SFML/Graphics.hpp>
//#include "Game.h"
#include "Menu.h"
#include <time.h>
#include <sstream>

/*void menu(sf::RenderWindow& window) {
	sf::Font font;
	font.loadFromFile("sansation.ttf");
	sf::Text game("Menu", font, 30);
	game.setPosition(160, 100);
	//game.setFillColor(sf::Color::Black);
	sf::Text play("Play", font, 30);
	play.setPosition(170,150);
	//play.setFillColor(sf::Color::Black);
	sf::Text exit("Exit", font, 30);
	exit.setPosition(170, 200);
	//exit.setFillColor(sf::Color::Black);

	//sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;


	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		game.setFillColor(sf::Color::White);
		play.setFillColor(sf::Color::White);
		exit.setFillColor(sf::Color::White);
		//menu3.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(129, 181, 221));

		//if (sf::IntRect(100, 30, 300, 50).contains(sf::Mouse::getPosition(window))) { game.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect(170, 150, 300, 50).contains(sf::Mouse::getPosition(window))) { play.setFillColor(sf::Color::Blue); menuNum = 2; }
		if (sf::IntRect(170, 200, 300, 50).contains(sf::Mouse::getPosition(window))) { exit.setFillColor(sf::Color::Blue); menuNum = 3; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { Game(window); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(game);
		window.draw(play);
		window.draw(exit);
		//window.draw(menu3);

		window.display();
	}
	////////////////////////////////////////////////////
}*/

int main(){
	sf::RenderWindow window(sf::VideoMode(400,400),"Minesweeper!");
	Menu menu(window.getSize().x, window.getSize().y);
	menu.Draw(window);
	return 0;
}

/*using namespace sf;
int mine = 0;

//Ширина клетки
int w = 32;
int gridLogic[12][12];
int gridView[12][12];

void Init() {
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			gridView[i][j] = 10;
		}

}void MineInit() {
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			if (rand() % 5 == 0) {
				gridLogic[i][j] = 9;
				mine++;
			}
			else gridLogic[i][j] = 0;
		}

}

void NumberGenerate() {
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
}

int main()
{

	//Генератор случайных чисел
	srand(time(0));

	RenderWindow app(VideoMode(400, 400), "Minesweeper!");
	//view.reset(FloatRect(0,0,400,400));
	int mine = 0;

	//Ширина клетки
	int w = 32;
	int gridLogic[12][12];
	int gridView[12][12];

	Font font;
	font.loadFromFile("sansation.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::Black);

	//Загрузка текстуры и создание спрайта
	Texture t;
	t.loadFromFile("images/tiles.jpg");
	Sprite s(t);
	Init();
	
	//Подсчет мин вокруг каждой клетки
	

	while (app.isOpen())
	{
		//Получаем координаты мыши относительно окна нашего приложения
		Vector2i pos = Mouse::getPosition(app);
		int x = pos.x / w;
		int y = pos.y / w;

		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
			//Была нажата кнопка мыши…?
			if (e.type == Event::MouseButtonPressed)
				//Если это - левая кнопка мыши, то открываем клетку
				if (e.key.code == Mouse::Left) {
					MineInit();
					NumberGenerate();
					gridView[x][y] = gridLogic[x][y];
				}
			//Если это – правая кнопка мыши, то отображаем флажок
				else if (e.key.code == Mouse::Right) {
					gridView[x][y] = 11;
					mine--;
				}
		}

		//Устанавливаем белый фон
		app.clear(Color::White);

		std::ostringstream ss;    // #include <sstream>
		ss << mine;
		text.setString("Mines: " + ss.str());
		text.setPosition(0, 0);
		app.draw(text);

		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++)
			{
				if (gridView[x][y] == 9) gridView[i][j] = gridLogic[i][j];
				//Вырезаем из спрайта нужный нам квадратик текстуры
				s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
				//Устанавливаем его заданную позицию…
				s.setPosition(i * w, j * w);
				//… и отрисовываем
				app.draw(s);
			}
		//отображаем всю композицию на экране
		app.display();
	}

	return 0;
}
*/


/*int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Minesweeper");
    Game game;
    game.SetPosition(50.f,50.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
*/