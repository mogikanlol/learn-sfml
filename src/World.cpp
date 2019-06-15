#include "World.hpp"

World::World(int width, int height, int l_blockSize): blockSize(l_blockSize), snake(blockSize), width(width), height(height), apple(l_blockSize) {
	srand(time(nullptr));
	SpawnApple();
}

World::~World() {}

void World::Update() {
	if (apple.eated) {
		SpawnApple();
	}
	CheckCollisions();
	snake.Update();
}

void World::Draw(sf::RenderWindow& window) {
	snake.Draw(window);
	apple.Draw(window);
}

void World::HandleInput() {
	snake.HandleInput();
}

void World::CheckCollisions() {
	
	sf::Vector2f snakePosition = snake.GetPosition();
	sf::Vector2f applePosition = apple.GetPosition();
	
	if (snakePosition.x >= width || snakePosition.x < 0 ||
		snakePosition.y >= height || snakePosition.y < 0) {
		snake.Reset();
	}

	if (snakePosition.x == applePosition.x && snakePosition.y == applePosition.y) {
		snake.Grow();
		apple.eated = true;
	}
}

void World::SpawnApple() {
	float x = rand() % (width / blockSize);
	float y = rand() % (height / blockSize);

	sf::Vector2f newPosition( x * blockSize, y * blockSize );

	for (auto& s : snake.GetBody()) {
		if (s.getPosition().x == newPosition.x && s.getPosition().y == newPosition.y) {
			SpawnApple();
		}
	}

	apple.SetPosition({ x * blockSize, y * blockSize });
	apple.eated = false;
}