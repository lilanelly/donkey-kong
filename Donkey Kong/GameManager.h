#pragma once
#include <SFML/Graphics.hpp>
//#include <iostream>
#include "Mario.h"

class GameManager {
private:
	bool m_is_running;
	Mario m_mario;
	sf::RenderWindow m_window;

	void draw();
	void update(float dt);
	void handle_events();
	void handle_keyboard();
public:
	GameManager();
	void game_init();
};
