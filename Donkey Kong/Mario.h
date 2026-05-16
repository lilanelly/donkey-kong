#pragma once
#include <SFML/Graphics.hpp>

enum class Direction {
	RIGHT,
	LEFT
};

class Mario {
private:
	sf::RectangleShape m_square;
public:
	Mario();

	Direction m_direction;

	void draw(sf::RenderWindow& window) const;
	void update(float dt);
	void move(float dt);
	void setDirection(Direction dir);
};
