#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

enum class Direction {
	None, UP, Down, Left, Right
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

	void Reset();
private:
	std::vector<sf::RectangleShape> body;
	sf::Vector2f dir;
	int blockSize;
};