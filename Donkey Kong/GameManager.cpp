#include "GameManager.h"

GameManager::GameManager()
	: m_window(sf::VideoMode::getDesktopMode(), "Donkey Kong", sf::Style::Default, sf::State::Fullscreen), m_is_running(false) {}

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
	m_mario.draw(m_window);

	/*
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::Red);
	rect.setSize({ 50, 50 });
	rect.setPosition({ 100, 100 });
	m_window.draw(rect);
	*/

	m_window.display();
}

void GameManager::update(float dt) {

}

void GameManager::handle_keyboard() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape)) {
		m_is_running = false;
	}
}
