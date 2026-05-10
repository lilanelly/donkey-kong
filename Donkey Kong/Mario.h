#pragma once
#include <SFML/Graphics.hpp>

class Mario {
private:
	sf::RectangleShape m_my_square;
public:
	Mario();

	void draw(sf::RenderWindow& window) const;
	void update();
};
