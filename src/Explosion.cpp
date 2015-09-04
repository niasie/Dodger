/*
 * Explosion.cpp
 *
 *  Created on: 24.08.2015
 *      Author: Siegenni
 */

#include "Explosion.h"

#include <iostream>
#include <iterator>
#include <vector>
#include <string>

Explosion::Explosion(sf::Vector2f pos, sf::Texture& tempTexture, float scale)
: Entity(pos.x, pos.y)
{
	sf::Sprite tempSprite;
	tempSprite.setTexture(tempTexture);
	tempSprite.setPosition(pos);

	for (int i = 1; i != tempTexture.getSize().x / 64; i++)
	{
		tempSprite.setTextureRect(sf::Rect<int>(i * 64, 0, 64, 64));
		_animFrames.push_back(tempSprite);
	}

	_sprite = *_animFrames.begin();
	_sprite.setScale(scale, scale);

	_size.x = tempTexture.getSize().x / 8;
	_size.y = tempTexture.getSize().y;

	_sprite.setOrigin(this->getSize().x / 2, this->getSize().y / 2);

	// _sprite.setTexture(tempTexture);
}

void Explosion::update()
{

	if (_animTimer.getElapsedTime().asMilliseconds() > _durationAnimFrame)
	{
		// std::cout << (_currentFrame->getTextureRect() != _animFrames.back().getTextureRect()) << std::endl;

		/*
		if (_currentFrame->getTextureRect() != _animFrames.back().getTextureRect())
		{
			std::cout << "test" << std::endl;
			_currentFrame++;

			_sprite = *_currentFrame;
		}
		*/

		for (std::vector<sf::Sprite>::iterator p = _animFrames.begin(); p != _animFrames.end(); p++)
		{
			if (p->getTextureRect() == _sprite.getTextureRect())
			{
				p++;

				_sprite.setTextureRect(p->getTextureRect());

				break;
			}
		}

		_animTimer.restart();
	}

}

bool Explosion::isAnimFinished()
{
	return _sprite.getTextureRect() == _animFrames.end()->getTextureRect();
}

