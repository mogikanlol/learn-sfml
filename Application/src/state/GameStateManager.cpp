#include "GameStateManager.hpp"
#include "SnakeGameState.hpp"

GameStateManager::GameStateManager()
{
	this->activeState = new SnakeGameState(this);
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::update(float delta)
{
	activeState->update(delta);
}

void GameStateManager::draw(sf::RenderWindow& window)
{
	activeState->draw(window);
}

void GameStateManager::handleInput()
{
	activeState->handleInput();
}

void GameStateManager::setState(GameStateName name)
{
	switch (name)
	{
	case GameStateName::SNAKE_GAME:
		this->activeState = new SnakeGameState(this);
		break;
	default:
		break;
	}
}
