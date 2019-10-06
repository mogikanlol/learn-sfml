#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Apple.hpp"
#include "Border.hpp"

class World {

public:
	World(int width, int height, int blockSize);
	~World();

	void update();
	void draw(sf::RenderWindow& window);
	void handleInput();

private:
	void checkCollisions();
	void spawnApple();

private:
	int blockSize;

	Snake snake;
	Apple apple;
	Border border;
};