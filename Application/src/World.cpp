#include "World.hpp"

World::World(int width, int height, int blockSize):
	blockSize(blockSize), snake(blockSize), apple(blockSize), border(width, height, blockSize)
{
	srand(time(nullptr));
	spawnApple();
}

World::~World() {}

void World::update() {
	
	snake.update();
	checkCollisions();
	if (apple.eated) {
		spawnApple();
	}
}

void World::draw(sf::RenderWindow& window) {
	border.draw(window);
	snake.draw(window);
	apple.draw(window);
}

void World::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		snake.setDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		snake.setDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		snake.setDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		snake.setDirection(Direction::Right);
	}
}

void World::checkCollisions() {
	
	sf::Vector2f snakePosition = snake.getPosition();
	sf::Vector2f applePosition = apple.getPosition();
	
	if (snakePosition.x >= border.getRight() || snakePosition.x < border.getLeft() ||
		snakePosition.y >= border.getBottom() || snakePosition.y < border.getTop()) {
		snake.reset();
	}

	if (snake.getBody().size() > 4) {
		auto body = snake.getBody();
		for (int i = 4; i < body.size(); i++) {
			if (body[0].getPosition() == body[i].getPosition()) {
				snake.reset();
			}
		}
	}

	if (snakePosition.x == applePosition.x && snakePosition.y == applePosition.y) {
		snake.grow();
		apple.eated = true;
	}
}

void World::spawnApple() {
	
	int xRange = border.getRight() - border.getLeft();
	int yRange = border.getBottom() - border.getTop();

	float x = (rand() % (xRange / blockSize)) * blockSize + blockSize;
	float y = (rand() % (yRange/ blockSize)) * blockSize + blockSize;

	sf::Vector2f newPosition(x , y);

	for (auto& s : snake.getBody()) {
		if (s.getPosition() == newPosition) {
			return;
		}
	}

	apple.setPosition(newPosition);
	apple.eated = false;
}