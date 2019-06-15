#pragma once

#include <SFML/Graphics.hpp>

struct Apple {
	
	Apple(int size) : eated(false) {
		shape.setFillColor(sf::Color::Red);
		shape.setSize(sf::Vector2f(size - 1, size - 1));
	};

	void Draw(sf::RenderWindow& renderWindow) {
		if (!eated) {
			renderWindow.draw(shape);
		}
	}

	void SetPosition(sf::Vector2f position) {
		shape.setPosition(position);
	}

	sf::Vector2f GetPosition() {
		return shape.getPosition();
	}

	sf::RectangleShape shape;
	bool eated;
};