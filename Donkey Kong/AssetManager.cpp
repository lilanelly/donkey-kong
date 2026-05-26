#include <iostream>

#include "AssetManager.h"

AssetManager::AssetManager() {

}

void AssetManager::addTexture(
	std::string texture_name, 
	std::string file_path, 
	sf::IntRect mask
) {
	sf::Texture texture;
	if (!texture.loadFromFile(file_path, false, mask)) {
		std::cerr << "File does not exist.\n";
		return;
	}
	m_textures.insert({ texture_name, texture });
}

sf::Texture& AssetManager::getTexture(std::string texture_name) {
	if (m_textures.find(texture_name) == m_textures.end()) {
		std::cerr << "Texture does not exist.\n";
		// YOU HAVE TO RETURN SOMETHING HERE
	}
	return m_textures[texture_name];
}
