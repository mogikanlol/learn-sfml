#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class MenuItem {

public:
	MenuItem();
	MenuItem(const std::string& title, int x, int y, sf::Font& font);
	~MenuItem();
	
	// https://stackoverflow.com/questions/51615363/how-to-write-c-getters-and-setters
	// TODO: learn about 'const'
	const sf::Text& getText() const;

	void setColor(sf::Color& color);

private:
	sf::Text text;
};