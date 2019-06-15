#include "World.hpp"

World::World(int width, int height, int l_blockSize): 
	blockSize(l_blockSize), snake(blockSize), apple(l_blockSize), border(width, height, blockSize)
{
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
	border.Draw(window);
	snake.Draw(window);
	apple.Draw(window);
}

void World::HandleInput() {
	snake.HandleInput();
}

void World::CheckCollisions() {
	
	sf::Vector2f snakePosition = snake.GetPosition();
	sf::Vector2f applePosition = apple.GetPosition();
	
	if (snakePosition.x >= border.Right() || snakePosition.x < border.Left() ||
		snakePosition.y >= border.Bottom() || snakePosition.y < border.Top()) {
		snake.Reset();
	}

	if (snakePosition.x == applePosition.x && snakePosition.y == applePosition.y) {
		snake.Grow();
		apple.eated = true;
	}
}

void World::SpawnApple() {
	
	int xRange = border.Right() - border.Left();
	int yRange = border.Bottom() - border.Top();

	float x = (rand() % (xRange / blockSize)) * blockSize + blockSize;
	float y = (rand() % (yRange/ blockSize)) * blockSize + blockSize;

	sf::Vector2f newPosition(x , y);

	for (auto& s : snake.GetBody()) {
		if (s.getPosition().x == newPosition.x && s.getPosition().y == newPosition.y) {
			SpawnApple();
		}
	}

	apple.SetPosition(newPosition);
	apple.eated = false;
}