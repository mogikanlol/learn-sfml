#include "Window.hpp"

Window::Window() {
	setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string& title, const sf::Vector2u& size) {
	setup(title, size);
}

Window::~Window() {
	destroy();
}

void Window::setup(const std::string& title, const sf::Vector2u& size) {
	windowTitle = title;
	windowSize = size;
	fullScreenEnabled = false;
	opened = true;
	create();
}

void Window::create() {
	using namespace sf;
	auto style = fullScreenEnabled ? Style::Fullscreen : Style::Default;

	window.create({ windowSize.x, windowSize.y, 32 }, windowTitle, style);
}

void Window::destroy() {
	window.close();
}

void Window::update() {
	sf::Event event;
	
	while (this->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			this->opened = false;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
			toggleFullScreen();
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			this->opened = false;
		}
	}
}

void Window::toggleFullScreen() {
	fullScreenEnabled = !fullScreenEnabled;
	destroy();
	create();
}

void Window::beginDraw() {
	window.clear(sf::Color::Black);
}

void Window::endDraw() {
	window.display();
}

bool Window::isOpened() {
	return opened;
}

bool Window::isFullScreen() {
	return fullScreenEnabled;
}

sf::Vector2u Window::getWindowSize() {
	return windowSize;
}

void Window::draw(sf::Drawable& drawable) {
	window.draw(drawable);
}

sf::RenderWindow& Window::getRenderWindow() {
	return window;
}
