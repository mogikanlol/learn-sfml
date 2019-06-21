#pragma once
#include "Window.hpp"
#include "World.hpp"

class Game {
public:
	Game();
	~Game();
	void Run();

private:
	void RestartClock();
	void HandleInput();
	void Update();
	void Render();

	void ResetTimestep();

private:
	Window window;
	sf::Clock clock;
	sf::Time elapsedTime;
	
	World world;

	float timeStep;
};