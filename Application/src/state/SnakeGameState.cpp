#include "SnakeGameState.hpp"

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
	world.handleInput();
}
