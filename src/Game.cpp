#include "Game.hpp"

Game::Game() : window("The Snake", sf::Vector2u(800, 600)), world(800, 600, 20) {
	resetTimestep();
}

Game::~Game() {}

void Game::Run() {
	while (window.isOpened()) {
		handleInput();

		if (elapsedTime.asSeconds() > timeStep) {
			update();
			render();
			elapsedTime -= sf::seconds(timeStep);
		}

		restartClock();
	}
}

void Game::update() {
	window.update();
	world.update();
}

void Game::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		timeStep = 0.06;
	}
	else {
		resetTimestep();
	}

	world.handleInput();
}

void Game::render() {
	window.beginDraw();
	world.draw(window.getRenderWindow());
	window.endDraw();
}

void Game::restartClock() {
	elapsedTime += clock.restart();
}

void Game::resetTimestep() {
	timeStep = 0.12;
}