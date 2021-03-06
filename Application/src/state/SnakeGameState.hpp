#pragma once

//#include <SFML/Graphics.hpp>

#include "GameState.hpp"
#include "../snake/World.hpp"

namespace sf {
	class RenderWindow;
}

class SnakeGameState : public GameState {

public:

	SnakeGameState(GameStateManager* gsm);

	void update(float delta) override;
	void draw(sf::RenderWindow& window) override;
	void handleInput() override;

private:
	World world;
};