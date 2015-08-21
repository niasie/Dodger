/*
 * entity.cpp
 *
 *  Created on: 09.10.2014
 *      Author: Niall
 */

#include "entity.hpp"
#include <iostream>

Entity::Entity(std::string name, sf::Texture& tex, int x, int y)
{
	_name 			= name;
	// _pathToSprite 	= pathToSprite;
	_pos			= sf::Vector2i(x, y);
	_movementSpeed 	= 1;
	_scale			= 1;

	// if (!_texture.loadFromFile(pathToSprite)) std::cout << "Error loading texture.";
	_sprite.setTexture(tex);
	_sprite.setPosition((float) _pos.x, (float) _pos.y);

	_size.x = tex.getSize().x;
	_size.y = tex.getSize().y;
}


Entity::Entity(std::string name, std::string pathToTex, int x, int y)
{
	_name 			= name;
	_pathToTex	 	= pathToTex;
	_pos			= sf::Vector2i(x, y);
	_movementSpeed 	= 1;
	_scale			= 1;

	if (!_texture.loadFromFile(pathToTex)) std::cout << "Error loading texture.";
	_sprite.setTexture(_texture);
	_sprite.setPosition((float) _pos.x, (float) _pos.y);

	_size.x = _texture.getSize().x;
	_size.y = _texture.getSize().y;
}

Entity::Entity(int x, int y)
{
	_pos			= sf::Vector2i(x, y);
	_movementSpeed 	= 1;
	_scale			= 1;
}

void Entity::update()
{

}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
}

void Entity::setPositionRel(int x, int y)
{
	_pos.x			= _pos.x + x;
	_pos.y	 		= _pos.y + y;

	_sprite.setPosition((float) _pos.x, (float) _pos.y);
}

void Entity::setTexture(sf::Texture& tex)
{
	_sprite.setTexture(tex);
	_sprite.setPosition((float) _pos.x, (float) _pos.y);

	_size.x = tex.getSize().x;
	_size.y = tex.getSize().y;
}

/*
sf::Vector2i Entity::getPosition()
{
	return (sf::Vector2i) _pos;
}
*/
