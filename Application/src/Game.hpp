#pragma once
#include "Window.hpp"
#include "World.hpp"

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

	void resetTimestep();

private:
	Window window;
	sf::Clock clock;
	sf::Time elapsedTime;
	
	World world;

	float timeStep;
};