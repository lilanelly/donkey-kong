#include "Mario.h"

Mario::Mario(sf::Texture& texture)
: m_sprite(texture)
{
	m_sprite.setScale(sf::Vector2f(3.f, 3.f)); //temp
}

void Mario::draw(sf::RenderWindow& window) const {
	window.draw(m_sprite);
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

	m_sprite.setPosition(m_sprite.getPosition() + m_velocity * dt);
}