#pragma once

#include <unordered_map>
#include <string>

#include <SFML/Graphics.hpp>

class AssetManager {
private:
	std::unordered_map<std::string, sf::Texture> m_textures;
public:
	AssetManager();
	sf::Texture& getTexture(std::string texture_name);
	void addTexture(std::string texture_name, std::string file_path, sf::IntRect mask);
};
