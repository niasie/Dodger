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
		Explosion();
		virtual ~Explosion();

		void update();
		void draw(sf::RenderWindow&);

	private:
		std::vector<sf::Sprite> _animFrames;
		std::vector<sf::Sprite>::iterator _currentFrame = _animFrames.begin();
		sf::Clock _animTimer;
		int _durationAnimFrame = 50;
};

#endif /* SRC_EXPLOSION_H_ */
