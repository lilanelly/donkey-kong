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
	m_velocity.x = 0.f;
	m_velocity.y = 0.f;

	float speed = 200.f;

	switch (m_direction) {
	case Direction::LEFT:
		m_velocity.x = -speed;
		break;
	case Direction::RIGHT:
		m_velocity.x = speed;
		break;
	case Direction::NONE:
	default:
		m_velocity.x = 0;
		break;
	}

	m_square.setPosition(m_square.getPosition() + m_velocity * dt);
}