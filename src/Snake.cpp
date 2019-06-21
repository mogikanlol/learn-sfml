#include "Snake.hpp"

Snake::Snake(int l_blockSize): blockSize(l_blockSize) {
	Reset();
}

Snake::~Snake() {}

void Snake::Update() {
	if (body.size() > 1) {

		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(blockSize - 1, blockSize - 1));
		shape.setPosition(body[0].getPosition());

		body.insert(body.begin(), shape);
		body.pop_back();

	}

	body[0].setPosition(body[0].getPosition() + vectorDir);

}

void Snake::Draw(sf::RenderWindow& renderWindow) {
	for (int i = 0; i < body.size(); i++) {
		if (i == 0) {
			body[i].setFillColor(sf::Color::Yellow);
		}
		else {
			body[i].setFillColor(sf::Color::Green);
		}
		renderWindow.draw(body[i]);
	}
}

std::vector<sf::RectangleShape>& Snake::GetBody()
{
	return body;
}

void Snake::setDirection(Direction direction)
{
	switch (direction) {
		case Direction::Up:
			if (currentDirection != Direction::Down) {
				vectorDir = sf::Vector2f(0, -blockSize);
				currentDirection = Direction::Up;
			}
			break;
		case Direction::Down:
			if (currentDirection != Direction::Up) {
				vectorDir = sf::Vector2f(0, blockSize);
				currentDirection = Direction::Down;
			}
			break;
		case Direction::Left:
			if (currentDirection != Direction::Right) {
				vectorDir = sf::Vector2f(-blockSize, 0);
				currentDirection = Direction::Left;
			}
			break;
		case Direction::Right:
			if (currentDirection != Direction::Left) {
				vectorDir = sf::Vector2f(blockSize, 0);
				currentDirection = Direction::Right;
			}
			break;
	}
}

void Snake::Reset() {
	body.clear();

	int startX = blockSize * 5;
	int startY = blockSize * 5;

	sf::RectangleShape head;
	head.setSize(sf::Vector2f(blockSize - 1, blockSize - 1));
	head.setPosition(startX, startY);

	sf::RectangleShape bone;
	bone.setSize(sf::Vector2f(blockSize - 1, blockSize - 1));
	bone.setPosition(startX - blockSize, startY);

	sf::RectangleShape tail;
	tail.setSize(sf::Vector2f(blockSize - 1, blockSize - 1));
	tail.setPosition(startX - blockSize * 2, startY);

	vectorDir = sf::Vector2f(blockSize, 0);
	currentDirection = Direction::Right;

	body.push_back(head);
	body.push_back(bone);
	body.push_back(tail);
}

void Snake::Grow() {
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(blockSize - 1, blockSize - 1));
	shape.setPosition(body.back().getPosition() - vectorDir);
	
	body.push_back(shape);
}

sf::Vector2f Snake::GetPosition() {
	return body[0].getPosition();
}