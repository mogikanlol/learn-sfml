#include "Game.hpp"

Game::Game() : window("The Snake", sf::Vector2u(800, 600)), world(800, 600, 20) {
	
}

Game::~Game() {}

void Game::Run() {
	while (window.isOpened()) {
		handleInput();

		update();
		render();

		restartClock();
	}
}

void Game::update() {
	window.update();
	world.update(elapsedTime.asSeconds());
}

void Game::handleInput() {
	world.handleInput();
}

void Game::render() {
	window.beginDraw();

	world.draw(window.getRenderWindow());

	window.endDraw();
}

void Game::restartClock() {
	elapsedTime = clock.restart();
}