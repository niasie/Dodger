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
#include "keyReader.hpp"
#include <math.h>
#include <iostream>

class Player : public Entity
{
	public:
		inline 			Player(int posX, int posY);
		inline void 	update(sf::RenderWindow&);

	private:
		KeyReader		_keyA, _keyD;
};

Player::Player(int posX, int posY)
	: Entity(posX, posY),
	_keyA(0, sf::Keyboard::A),
	_keyD(0, sf::Keyboard::D)
{

}

void Player::update(sf::RenderWindow& window)
{
	if (_keyA.isKeyPressed() && _pos.x > (-1 + _size.x / 2))
	{
		setPositionRel(-7, 0);
		_sprite.setOrigin(_size.x / 2, _size.y / 2);
		// _sprite.setOrigin(0, 0);
	}
	else if (_keyD.isKeyPressed() && _pos.x < (int) window.getSize().x - (_size.x / 2))
	{
		setPositionRel(7, 0);
		_sprite.setOrigin(_size.x / 2, _size.y / 2);
		// _sprite.setOrigin(0, 0);
	}
	else
	{
		_sprite.setOrigin(_size.x / 2, _size.y / 2);
		// _sprite.setOrigin(0, 0);
	}

	float rotation = (float) 180 / M_PI * atan(( -1 * (sf::Mouse::getPosition(window).y - _pos.y)) / (sf::Mouse::getPosition(window).x - _pos.x));
	std::cout << rotation << std::endl;
	// _sprite.setRotation(rotation);
}

#endif /* PLAYER_HPP_ */

