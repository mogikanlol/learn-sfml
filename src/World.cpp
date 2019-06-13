#include "World.hpp"

World::World(int width, int height, int l_blockSize): blockSize(l_blockSize), snake(blockSize), width(width), height(height) {

}

World::~World() {}

void World::Update() {
	CheckCollisions();
	snake.Update();
}

void World::Draw(sf::RenderWindow& window) {
	snake.Draw(window);
}

void World::HandleInput() {
	snake.HandleInput();
}

void World::CheckCollisions() {
	
	sf::Vector2f snakePosition = snake.GetPosition();
	
	if (snakePosition.x >= width || snakePosition.x < 0 ||
		snakePosition.y >= height || snakePosition.y < 0) {
		snake.Reset();
	}
}