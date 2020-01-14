#include "Game.hpp"

Game::Game() : window("The Snake", sf::Vector2u(800, 600)) {
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
	gsm.update(elapsedTime.asSeconds());
}

void Game::handleInput() {
	gsm.handleInput();
}

void Game::render() {
	window.beginDraw();

	gsm.draw(window.getRenderWindow());

	window.endDraw();
}

void Game::restartClock() {
	elapsedTime = clock.restart();
}