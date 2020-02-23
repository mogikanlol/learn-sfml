#include "GameStateManager.hpp"
#include "SnakeGameState.hpp"
#include "../menu/MenuState.hpp"

GameStateManager::GameStateManager()
{
	auto snakeGameState = new SnakeGameState(this);
	auto menuGameState = new MenuState(this);
	states.insert({ GameStateName::SNAKE_GAME, snakeGameState });
	states.insert({ GameStateName::MENU, menuGameState });


	this->activeState = menuGameState;
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
		this->activeState = states[GameStateName::SNAKE_GAME];
		break;
	case GameStateName::MENU:
		this->activeState = states[GameStateName::MENU];
		break;
	default:
		break;
	}
}
