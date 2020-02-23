#pragma once

#include "../state/GameState.hpp"
#include "MenuItem.hpp"

namespace sf {
	class RenderWindow;
}

class MenuState : public GameState {

public:
	MenuState(GameStateManager* gsm);

	void update(float delta) override;
	void draw(sf::RenderWindow& window) override;
	void handleInput() override;

private:
	MenuItem menuItems[4];
	sf::Font font;
};