#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameManager {
private:
	bool m_is_running;
	sf::RenderWindow m_window;

	void handle_events();
	void draw();
	void update(float dt);
	void handle_keyboard();
public:
	GameManager();
	void game_init();
};
