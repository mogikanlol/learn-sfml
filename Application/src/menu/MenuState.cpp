#include <SFML/Graphics.hpp>

#include "MenuState.hpp"
#include "../state/GameStateManager.hpp"


MenuState::MenuState(GameStateManager* gsm) : GameState(gsm)
{
	font.loadFromFile("arial.ttf");
	menuItems[0] = { "Start", 200, 200 + (50 * 0), font };
	menuItems[1] = { "Options", 200, 200 + (50 * 1), font };
	menuItems[2] = { "Credits", 200, 200 + (50 * 2), font };
	menuItems[3] = { "Exit", 200, 200 + (50 * 3), font };
}

void MenuState::update(float delta)
{
}

void MenuState::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; i++) {
		
		bool hovered = false;
		sf::Vector2i position = sf::Mouse::getPosition(window);
		auto itemBounds = menuItems[i].getText().getGlobalBounds();
		if (position.x >= itemBounds.left 
			&& position.x <= itemBounds.left + itemBounds.width
			&& position.y >= itemBounds.top
			&& position.y <= itemBounds.top + itemBounds.height) {
			hovered = true;
		}

		sf::Color whiteColor = sf::Color::White;
		sf::Color hoveredColor = sf::Color::Cyan;

		sf::Color itemColor = hovered ? hoveredColor : whiteColor;

		if (hovered && i == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gsm->setState(GameStateName::SNAKE_GAME);
		}

		menuItems[i].setColor(itemColor);
		window.draw(menuItems[i].getText());
	}
}

void MenuState::handleInput()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
		gsm->setState(GameStateName::SNAKE_GAME);
	}

}
