#pragma once

#include <SFML/Graphics.hpp>

struct Apple {
	
	Apple(int size) : eated(false) {
		shape.setFillColor(sf::Color::Red);
		shape.setRadius(size/2 - 1);
	};

	void draw(sf::RenderWindow& renderWindow) {
		if (!eated) {
			renderWindow.draw(shape);
		}
	}

	void setPosition(sf::Vector2f position) {
		shape.setPosition(position);
	}

	sf::Vector2f getPosition() {
		return shape.getPosition();
	}

	sf::CircleShape shape;
	bool eated;
};