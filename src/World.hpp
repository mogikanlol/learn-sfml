#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Apple.hpp"

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
	int width;
	int height;

	Snake snake;
	Apple apple;
};