#include "Mario.h"

Mario::Mario()
	:m_square({100, 100}) {
	m_square.setFillColor(sf::Color::Red);
}

void Mario::draw(sf::RenderWindow& window) const {
	window.draw(m_square);
}

void Mario::update(float dt) {
	move(dt);
}

void Mario::setDirection(Direction dir) {
	m_direction = dir;
}

void Mario::move(float dt) {
	int temp_x;
	int curr_y;
	switch (m_direction) {
	case Direction::LEFT:
		temp_x = m_square.getPosition().x - 200 * dt;
		curr_y = m_square.getPosition().y;
		m_square.setPosition(sf::Vector2f(temp_x, curr_y));
		break;
	case Direction::RIGHT:
		temp_x = m_square.getPosition().x + 200 * dt;
		curr_y = m_square.getPosition().y;
		m_square.setPosition(sf::Vector2f(temp_x, curr_y));
		break;
	default:
		break;
	}
}