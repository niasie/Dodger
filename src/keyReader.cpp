/*
 * keyReader.cpp
 *
 *  Created on: 01.02.2015
 *      Author: Siegenni
 */

#include "keyReader.hpp"

KeyReader::KeyReader(int delayMilli, sf::Keyboard::Key key)
{
	_delayMilli = delayMilli;
	_key = key;
}

bool KeyReader::isKeyPressed()
{
	_elapsed = _cooldown.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(_key) && _elapsed.asMilliseconds() > _delayMilli)
	{
		_cooldown.restart();
		return true;
	}
	else
		return false;

}
