#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Apple.hpp"
#include "Border.hpp"

class World {

public:
	World(int width, int height, int blockSize);
	~World();

	void update(float elapsedTime);
	void draw(sf::RenderWindow& window);
	void handleInput();

private:
	void checkCollisions();
	void spawnApple();
	void resetTimestep();

private:
	int blockSize;
	float timeStep;
	sf::Time elapsedTime;

	Snake snake;
	Apple apple;
	Border border;
};