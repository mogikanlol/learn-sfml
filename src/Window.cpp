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
	this->windowTitle = title;
	this->windowSize = size;
	this->isWindowFullScreen = false;
	this->isWindowDone = false;
	create();
}

void Window::create() {
	using namespace sf;
	auto style = isWindowFullScreen ? Style::Fullscreen : Style::Default;

	this->window.create({ windowSize.x, windowSize.y, 32 }, windowTitle, style);
}

void Window::destroy() {
	this->window.close();
}

void Window::update() {
	sf::Event event;

	while (this->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			this->isWindowDone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
			toggleFullScreen();
		}
	}
}

void Window::toggleFullScreen() {
	isWindowFullScreen = !isWindowFullScreen;
	destroy();
	create();
}

void Window::beginDraw() {
	window.clear(sf::Color::Black);
}

void Window::endDraw() {
	window.display();
}

bool Window::isDone() {
	return this->isWindowDone;
}

bool Window::isFullScreen() {
	return this->isWindowFullScreen;
}

sf::Vector2u Window::getWindowSize() {
	return this->windowSize;
}

void Window::draw(sf::Drawable& drawable) {
	this->window.draw(drawable);
}