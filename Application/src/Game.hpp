#pragma once
#include "Window.hpp"
#include "snake/World.hpp"

class Game {
public:
	Game();
	~Game();
	void Run();

private:
	void restartClock();
	void handleInput();
	void update();
	void render();

private:
	Window window;
	sf::Clock clock;
	sf::Time elapsedTime;
	
	World world;
};