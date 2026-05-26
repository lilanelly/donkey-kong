#include "GameManager.h"

GameManager::GameManager()
	: m_window(
		sf::VideoMode::getDesktopMode(), 
		"Donkey Kong", sf::Style::Default, 
		sf::State::Windowed), 
		m_is_running(false) 
{
	m_asset_manager.addTexture(
	"Mario", 
	"assets/characters_and_objects.png", 
	sf::IntRect(sf::Vector2i(1,1),sf::Vector2i(16,16))
	);
	m_mario = std::make_unique<Mario>(m_asset_manager.getTexture("Mario"));
}

void GameManager::game_init() {
	m_is_running = true;
	m_window.setFramerateLimit(60);
	
	sf::Clock clock;

	while (m_is_running && m_window.isOpen()) {
		float dt = clock.restart().asSeconds();

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
	m_mario->draw(m_window);
	m_window.display();
}

void GameManager::update(float dt) {
	m_mario->update(dt);
}

void GameManager::handle_keyboard() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape)) {
		m_is_running = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) {
		m_mario->setDirection(Direction::LEFT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right)) {
		m_mario->setDirection(Direction::RIGHT);
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right) && 
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) {
		m_mario->setDirection(Direction::NONE);
	}
}
