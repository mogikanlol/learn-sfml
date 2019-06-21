#include "Window.hpp"

Window::Window() {
	Setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string& title, const sf::Vector2u& size) {
	Setup(title, size);
}

Window::~Window() {
	Destroy();
}

void Window::Setup(const std::string& title, const sf::Vector2u& size) {
	windowTitle = title;
	windowSize = size;
	fullScreenEnabled = false;
	open = true;
	Create();
}

void Window::Create() {
	using namespace sf;
	auto style = fullScreenEnabled ? Style::Fullscreen : Style::Default;

	window.create({ windowSize.x, windowSize.y, 32 }, windowTitle, style);
}

void Window::Destroy() {
	window.close();
}

void Window::Update() {
	sf::Event event;
	
	while (this->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			this->open = false;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
			ToggleFullScreen();
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			this->open = false;
		}
	}
}

void Window::ToggleFullScreen() {
	fullScreenEnabled = !fullScreenEnabled;
	Destroy();
	Create();
}

void Window::BeginDraw() {
	window.clear(sf::Color::Black);
}

void Window::EndDraw() {
	window.display();
}

bool Window::IsOpen() {
	return open;
}

bool Window::IsFullScreen() {
	return fullScreenEnabled;
}

sf::Vector2u Window::GetWindowSize() {
	return windowSize;
}

void Window::Draw(sf::Drawable& drawable) {
	window.draw(drawable);
}

sf::RenderWindow& Window::getRenderWindow() {
	return window;
}
