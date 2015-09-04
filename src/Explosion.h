/*
 * Explosion.h
 *
 *  Created on: 24.08.2015
 *      Author: Siegenni
 */

#ifndef SRC_EXPLOSION_H_
#define SRC_EXPLOSION_H_

#include "entity.hpp"

class Explosion: public Entity
{
	public:
		Explosion(sf::Vector2f, sf::Texture&, float);

		void update();

		bool isAnimFinished();

	private:
		std::vector<sf::Sprite> _animFrames;
		sf::Clock _animTimer;
		int _durationAnimFrame = 40;
};

#endif /* SRC_EXPLOSION_H_ */
