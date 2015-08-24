/*
 * Explosion.cpp
 *
 *  Created on: 24.08.2015
 *      Author: Siegenni
 */

#include "Explosion.h"
#include <iostream>
#include <string>

Explosion::Explosion()
: Entity(0, 0)
{
	std::string fileLocation = "res/textures/5_explosion.png";
	if (!_texture.loadFromFile(fileLocation.c_str())) std::cout << "error" << std::endl;

	for (int i = 1; i != _texture.getSize().x / 64; i++)
	{
		sf::Sprite tempSprite;
		tempSprite.setTexture(_texture);
		tempSprite.setTextureRect(sf::Rect<int>(i * 64, 0, 64, 64));
		_animFrames.push_back(tempSprite);
	}

	_currentFrame = _animFrames.begin();
}

Explosion::~Explosion()
{
	// TODO Auto-generated destructor stub
}

void Explosion::update()
{
	if (_animTimer.getElapsedTime().asMilliseconds() > _durationAnimFrame)
	{
		if (_currentFrame != (_animFrames.end() - 1))
		{
			_currentFrame++;
		}
		else
		{
			_currentFrame = _animFrames.begin();
		}

		_animTimer.restart();
	}
}

void Explosion::draw(sf::RenderWindow& window)
{
	window.draw(*_currentFrame);
}

