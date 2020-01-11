#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

enum class Direction {
	None, Up, Down, Left, Right
};

class Snake {
public:
	Snake(int blockSize);
	~Snake();
	void update();
	void draw(sf::RenderWindow& renderWindow);
	void grow();
	void handleInput();
	sf::Vector2f getPosition();

	std::vector<sf::RectangleShape>& getBody();
	void setDirection(Direction direction);
	void reset();
private:
	std::vector<sf::RectangleShape> body;
	sf::Vector2f vectorDir;
	int blockSize;
	Direction currentDirection;
};