#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
	Window();
	Window(const std::string& title, const sf::Vector2u& size);
	~Window();

	void beginDraw(); // Clear the window
	void endDraw(); // Display the changes

	void update();

	bool isDone();
	bool isFullScreen();
	sf::Vector2u getWindowSize();

	void toggleFullScreen();

	void draw(sf::Drawable& drawable);

private:
	void setup(const std::string& title, const sf::Vector2u& size);
	void destroy();
	void create();

	sf::RenderWindow window;
	sf::Vector2u windowSize;
	std::string windowTitle;
	bool isWindowDone;
	bool isWindowFullScreen;
};