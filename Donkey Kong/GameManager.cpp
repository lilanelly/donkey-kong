#include "GameManager.h"

GameManager::GameManager()
	: m_window(sf::VideoMode(sf::Vector2u(800,600)),"Donkey Kong", sf::Style::Default,sf::State::Windowed), m_is_running(false) {}

void GameManager::game_init() {
	m_is_running = true;
	m_window.setFramerateLimit(60);
	
	sf::Clock clock;

	while (m_is_running && m_window.isOpen()) {
		float dt = clock.restart().asSeconds();
		//float fps = 1.f / dt;
		//std::cout << fps << '\n';

		handle_keyboard();
		handle_events();
		update(dt);
		draw();		
	}
}

void GameManager::handle_events() {
	while (const std::optional event = m_window.pollEvent()) {
		if (event->is<sf::Event::Closed>())
			m_window.close();
	}
}

void GameManager::draw() {
	m_window.clear();
	// draw here
	m_window.display();
}

void GameManager::update(float dt) {

}

void GameManager::handle_keyboard() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape)) {
		m_is_running = false;
	}
}
