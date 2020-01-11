#pragma once

#include <SFML/Graphics.hpp>

class Border {
public:
	Border(int width, int height, int blockSize);

	void draw(sf::RenderWindow& renderWindow);

	int getTop();
	int getBottom();
	int getLeft();
	int getRight();

private:
	int top;
	int bottom;
	int left;
	int right;
	int blockSize;

	sf::RectangleShape borders[4];
};