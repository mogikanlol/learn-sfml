#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
	Window();
	Window(const std::string& title, const sf::Vector2u& size);
	~Window();

	void BeginDraw(); // Clear the window
	void EndDraw(); // Display the changes

	void Update();

	bool IsOpen();
	bool IsFullScreen();
	sf::Vector2u GetWindowSize();

	void ToggleFullScreen();

	void Draw(sf::Drawable& drawable);

	sf::RenderWindow& getRenderWindow();

private:
	void Setup(const std::string& title, const sf::Vector2u& size);
	void Destroy();
	void Create();

	sf::RenderWindow window;
	sf::Vector2u windowSize;
	std::string windowTitle;
	bool open;
	bool fullScreenEnabled;
};