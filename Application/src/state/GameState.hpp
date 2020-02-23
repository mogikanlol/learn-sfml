#pragma once

class GameStateManager;

namespace sf {
	class RenderWindow;
}

class GameState {

public:
	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void handleInput() = 0;

protected:
	GameState(GameStateManager* gsm): gsm(gsm) {};

protected:
	GameStateManager* gsm;
};
