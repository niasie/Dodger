/*
 * Enemy.hpp
 *
 *  Created on: 29.07.2015
 *      Author: Siegenni
 */

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "entity.hpp"
#include <SFML/Graphics.hpp>

class Enemy : public Entity
{
	public:
		inline 			Enemy(sf::Texture& tex, int x, int y);
		inline void 	update();
};

Enemy::Enemy(sf::Texture& tex, int x, int y)
	: Entity("", tex, x, y)
{

}

void Enemy::update()
{
	Entity::update();

	setPositionRel(0, _movementSpeed);
}

#endif /* ENEMY_HPP_ */
