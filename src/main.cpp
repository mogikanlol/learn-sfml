#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "First window!");

	sf::Texture kappaTexture;
	kappaTexture.loadFromFile("assets/Kappa.png");

	sf::Sprite kappa(kappaTexture);

	sf::Vector2u size = kappaTexture.getSize();

	kappa.setOrigin(size.x / 2, size.y / 2);

	sf::Vector2f increment(0.2f, 0.2f);

	// game loop
	while (window.isOpen()) {
		sf::Event event;

		// event loop
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}

		if ((kappa.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) ||
			(kappa.getPosition().x - (size.x / 2) < 0 && increment.x < 0)) {
			increment.x = -increment.x;
		}
		if ((kappa.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) ||
			(kappa.getPosition().y - (size.y / 2) < 0 && increment.y < 0)) {
			increment.y = -increment.y;
		}
		kappa.setPosition(kappa.getPosition() + increment);

		window.clear(sf::Color::Black);

		// draw here

		window.draw(kappa);

		window.display();
	}

}