#pragma once

#include <map>

namespace sf {
	class RenderWindow;
}

class GameState;

enum class GameStateName {
	MENU,
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
	
	std::map<GameStateName, GameState*> states;
};