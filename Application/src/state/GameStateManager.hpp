#pragma once

#include <SFML/Graphics.hpp>

class GameState;

enum class GameStateName {
	SNAKE_GAME
};

class GameStateManager {
public:
	GameStateManager();
	~GameStateManager();

	void update(float delta);
	void draw(sf::RenderWindow& window);
	void handleInput();
	void setState(GameStateName name);

private:
	
	GameState* activeState;
	
};