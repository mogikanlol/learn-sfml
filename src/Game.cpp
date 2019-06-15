#include "Game.hpp"

Game::Game() : m_window("The Snake", sf::Vector2u(800, 600)), world(800, 600, 20) {
}

Game::~Game() {}

void Game::Run() {
	float timeStep = 0.12;
	while (!m_window.IsDone()) {
		HandleInput();

		if (m_elapsed.asSeconds() > timeStep) {
			Update();
			Render();
			m_elapsed -= sf::seconds(timeStep);
		}

		RestartClock();
	}
}

void Game::Update() {
	m_window.Update();
	world.Update();
}

void Game::HandleInput() {
	world.HandleInput();
}

void Game::Render() {
	m_window.BeginDraw();
	world.Draw(m_window.getRenderWindow());
	m_window.EndDraw();
}

void Game::RestartClock() {
	m_elapsed += m_clock.restart();
}