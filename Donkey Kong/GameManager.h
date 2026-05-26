#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "AssetManager.h"
#include "Mario.h"

class GameManager {
private:
	bool m_is_running;
	std::unique_ptr<Mario> m_mario;
	sf::RenderWindow m_window;
	AssetManager m_asset_manager;

	void draw();
	void update(float dt);
	void handle_events();
	void handle_keyboard();
public:
	GameManager();
	void game_init();
};
