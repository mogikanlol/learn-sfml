#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Apple.hpp"
#include "Border.hpp"

class World {

public:
	World(int width, int height, int l_blockSize);
	~World();

	void Update();
	void Draw(sf::RenderWindow& window);
	void HandleInput();

private:
	void CheckCollisions();
	void SpawnApple();

private:
	int blockSize;

	Snake snake;
	Apple apple;
	Border border;
};