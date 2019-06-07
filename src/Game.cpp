#include "Game.hpp"

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600)) {
	m_kappaTexture.loadFromFile("assets/Kappa.png");
	m_kappa.setTexture(m_kappaTexture);
	m_increment = sf::Vector2i(4, 4);
}

Game::~Game() {}

void Game::Update() {
	m_window.Update();
	MoveKappa();
}

void Game::HandleInput() {

}

void Game::MoveKappa() {
	sf::Vector2u l_windowSize = m_window.GetWindowSize();
	sf::Vector2u l_textureSize = m_kappaTexture.getSize();

	if ((m_kappa.getPosition().x >
		l_windowSize.x - l_textureSize.x && m_increment.x > 0) ||
		(m_kappa.getPosition().x < 0 && m_increment.x < 0)) {
		m_increment.x = -m_increment.x;
	}
	if ((m_kappa.getPosition().y >
		l_windowSize.y - l_textureSize.y && m_increment.y > 0) ||
		(m_kappa.getPosition().y < 0 && m_increment.y < 0)) {
		m_increment.y = -m_increment.y;
	}
	m_kappa.setPosition(
		m_kappa.getPosition().x + m_increment.x,
		m_kappa.getPosition().y + m_increment.y);
}

void Game::Render() {
	m_window.BeginDraw();
	m_window.Draw(m_kappa);
	m_window.EndDraw();
}

Window* Game::GetWindow() {
	return &this->m_window;
}