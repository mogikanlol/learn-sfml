#pragma once

class GameStateManager;

class GameState {

public:
	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void handleInput() = 0;

public:
	GameState(GameStateManager* gsm): gsm(gsm) {};

private:
	GameStateManager* gsm;
};
