#pragma once

#include <SFML/Graphics.hpp>

class Border {
public:
	Border(int width, int height, int blockSize);

	void Draw(sf::RenderWindow& renderWindow);

	int Top();
	int Bottom();
	int Left();
	int Right();

private:
	int top;
	int bottom;
	int left;
	int right;
	int blockSize;

	sf::RectangleShape borders[4];
};