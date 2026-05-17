#pragma once
#include <SFML/Graphics.hpp>

enum class Direction {
	RIGHT,
	LEFT,
	NONE
};

class Mario {
private:
	sf::RectangleShape m_square;
	sf::Vector2f m_velocity;
	Direction m_direction;
public:
	Mario();

	void draw(sf::RenderWindow& window) const;
	void update(float dt);
	void move(float dt);
	void setDirection(Direction dir);
};
