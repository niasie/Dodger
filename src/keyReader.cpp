/*
 * keyReader.cpp
 *
 *  Created on: 01.02.2015
 *      Author: Siegenni
 */

#include "keyReader.hpp"

KeyReader::KeyReader(int delayMilli)
{
	_delayMilli = delayMilli;
}

bool KeyReader::isKeyPressed(sf::Keyboard::Key key)
{
	_elapsed = _cooldown.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(key) && _elapsed.asMilliseconds() > _delayMilli)
	{
		_cooldown.restart();
		return true;
	}
	else
		return false;

}
