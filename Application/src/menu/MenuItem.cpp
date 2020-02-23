#include "MenuItem.hpp"

MenuItem::MenuItem() {}
MenuItem::MenuItem(const std::string& title, int x, int y, sf::Font& font)
{
	this->text.setString(title);
	this->text.setFont(font);
	this->text.setPosition(x, y);
}

MenuItem::~MenuItem()
{

}

const sf::Text& MenuItem::getText() const
{
	return this->text;
}

void MenuItem::setColor(sf::Color& color)
{
	this->text.setColor(color);
}



