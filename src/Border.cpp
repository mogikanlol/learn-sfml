#include "Border.hpp"

Border::Border(int width, int height, int blockSize): blockSize(blockSize) {
	
	for (int i = 0; i < sizeof(borders) / sizeof(*borders); i++) {
	
		if (i % 2 == 0) {
			borders[i].setSize(sf::Vector2f(width, blockSize));
		}
		else {
			borders[i].setSize(sf::Vector2f(blockSize, height));
		}

		if (i < 2) {
			borders[i].setPosition(0, 0);
		}
		else {
			borders[i].setOrigin(borders[i].getSize());
			borders[i].setPosition(width, height);
		}
		borders[i].setFillColor(sf::Color(0, 50, 100));
	}

	top = blockSize;
	bottom = height - blockSize;
	left = blockSize;
	right = width - blockSize;

}

void Border::Draw(sf::RenderWindow& renderWindow) {
	for (auto& b : borders) {
		renderWindow.draw(b);
	}
}

int Border::Top() {
	return top;
}
int Border::Bottom() {
	return bottom;
}
int Border::Left() {
	return left;
}
int Border::Right() {
	return right;
}