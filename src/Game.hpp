#pragma once
#include "Window.hpp"

class Game {
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();

private:
	void MoveKappa();
	Window m_window;
	sf::Texture m_kappaTexture;
	sf::Sprite m_kappa;
	sf::Vector2i m_increment;
	sf::Clock m_clock;
	sf::Time m_elapsed;
};