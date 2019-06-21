#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

enum class Direction {
	None, Up, Down, Left, Right
};

class Snake {
public:
	Snake(int l_blockSize);
	~Snake();
	void Update();
	void Draw(sf::RenderWindow& renderWindow);
	void Grow();
	void HandleInput();
	sf::Vector2f GetPosition();

	std::vector<sf::RectangleShape>& GetBody();
	void setDirection(Direction direction);
	void Reset();
private:
	std::vector<sf::RectangleShape> body;
	sf::Vector2f vectorDir;
	int blockSize;
	Direction currentDirection;
};