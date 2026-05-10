#include "Mario.h"

Mario::Mario()
	:m_my_square({100, 100}) {
	m_my_square.setFillColor(sf::Color::Red);
}

void Mario::draw(sf::RenderWindow& window) const {
	window.draw(m_my_square);
}

void Mario::update() {

}
