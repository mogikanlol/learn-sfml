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

	body[0].setPosition(body[0].getPosition() + dir);

}

void Snake::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		dir = sf::Vector2f(0, -blockSize);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		dir = sf::Vector2f(0, blockSize);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		dir = sf::Vector2f(-blockSize, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		dir = sf::Vector2f(blockSize, 0);
	}
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

	dir = sf::Vector2f(blockSize, 0);

	body.push_back(head);
	body.push_back(bone);
	body.push_back(tail);
}

void Snake::Grow() {

}

sf::Vector2f Snake::GetPosition() {
	return body[0].getPosition();
}