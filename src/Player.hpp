/*
 * Player.hpp
 *
 *  Created on: 29.07.2015
 *      Author: Siegenni
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "entity.hpp"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
	public:
		inline 			Player(int posX, int posY);
		inline void 	update(int windowSizeX);
};

Player::Player(int posX, int posY)
	: Entity(posX, posY)
{

}

void Player::update(int windowSizeX)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _pos.x > -1)
	{
		setPositionRel(-7, 0);
		_sprite.setOrigin(_size.x / 2, _size.y / 2);
		_sprite.setRotation(315);
		// _sprite.setOrigin(0, 0);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _pos.x < (int) windowSizeX - _size.x)
	{
		setPositionRel(7, 0);
		_sprite.setOrigin(_size.x / 2, _size.y / 2);
		_sprite.setRotation(45);
		// _sprite.setOrigin(0, 0);
	}

	else
	{
		_sprite.setOrigin(_size.x / 2, _size.y / 2);
		_sprite.setRotation(0);
		// _sprite.setOrigin(0, 0);
	}
}

#endif /* PLAYER_HPP_ */

