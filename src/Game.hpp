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

private:
	Window m_window;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	
	World world;
};