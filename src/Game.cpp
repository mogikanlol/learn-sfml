#include "Game.hpp"

Game::Game() : window("The Snake", sf::Vector2u(800, 600)), world(800, 600, 20) {
	ResetTimestep();
}

Game::~Game() {}

void Game::Run() {
	while (window.IsOpen()) {
		HandleInput();

		if (elapsedTime.asSeconds() > timeStep) {
			Update();
			Render();
			elapsedTime -= sf::seconds(timeStep);
		}

		RestartClock();
	}
}

void Game::Update() {
	window.Update();
	world.Update();
}

void Game::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		timeStep = 0.06;
	}
	else {
		ResetTimestep();
	}

	world.HandleInput();
}

void Game::Render() {
	window.BeginDraw();
	world.Draw(window.getRenderWindow());
	window.EndDraw();
}

void Game::RestartClock() {
	elapsedTime += clock.restart();
}

void Game::ResetTimestep() {
	timeStep = 0.12;
}