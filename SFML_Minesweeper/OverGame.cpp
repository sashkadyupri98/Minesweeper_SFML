#include "OverGame.h"
#include "Game.h"
using namespace sf;
OverGame::OverGame(float width, float height)
{
	font.loadFromFile("sansation.ttf");
	// Play Button
	menu[0].setFont(font);
	menu[0].setCharacterSize(20);
	menu[0].setString("Restart");
	//menu[0].setPosition(Vector2f(width / 2, height / 2));
	menu[0].setPosition(180, 141);

	// Exit Button
	menu[1].setFont(font);
	menu[1].setCharacterSize(20);
	menu[1].setString("Back to menu");
	//menu[1].setPosition(Vector2f(width / 2, height / 1.7));
	menu[1].setPosition(150, 200);

	selectedItemIndex = 0;

}
void OverGame::Draw(RenderWindow& window)
{
	WindowSize = window.getSize();
	bool isMenu = 1;

	while (isMenu)
	{
		menu[0].setFillColor(Color::White);
		menu[1].setFillColor(Color::White);

		//std::cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << std::endl;

		for (int i = 0; i < 3; i++) {
			if (menu[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {
				menu[i].setFillColor(Color::Blue);
				selectedItemIndex = i;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (selectedItemIndex == 0) {
				Game game(window, window.getSize().x, window.getSize().y);
				//game.Draw(window);
				isMenu = false;
			}//если нажали первую кнопку, то выходим из меню 
			//if (menuNum == 2) { Game(window); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
			if (selectedItemIndex == 1) { window.close(); isMenu = false; }

		}

		//window.clear();
		window.clear(sf::Color(129, 181, 221));
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
			window.draw(menu[i]);
		}

		//window.draw(menu3);

		window.display();
	}
}