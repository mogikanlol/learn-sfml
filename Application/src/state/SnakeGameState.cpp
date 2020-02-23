#include "SnakeGameState.hpp"
#include "GameStateManager.hpp"

SnakeGameState::SnakeGameState(GameStateManager* gsm):
	GameState(gsm), 
	world(800, 600, 20)
{
}

void SnakeGameState::update(float delta)
{
	world.update(delta);
}

void SnakeGameState::draw(sf::RenderWindow& window)
{
	world.draw(window);
}

void SnakeGameState::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
		gsm->setState(GameStateName::MENU);
	}

	world.handleInput();
}
