#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class Tile {
public:
	Tile() = default;
	Tile(sf::Vector2f size, sf::Vector2f pos, std::shared_ptr<sf::Texture> texture)
		: tile_size{size} {
		shape.setSize(tile_size);
		shape.setPosition(pos);
		shape.setTexture(texture.get());
		// shape.setOutlineColor(sf::Color::Green);
		// shape.setOutlineThickness(1);
	}
	void Render(sf::RenderWindow* window) {
		window->draw(shape);
	}

	sf::FloatRect getTileBounds() {return shape.getGlobalBounds();}
	sf::Vector2f getTileSize() {return tile_size;}

	virtual bool isWall() const {return false;}
	virtual std::string isType() {return "tile";}
private:
	sf::RectangleShape shape;
	// std::unique_ptr<sf::Texture> texture;
	sf::Vector2f tile_size;
};