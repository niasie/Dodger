/*
 * keyReader.hpp
 *
 *  Created on: 01.02.2015
 *      Author: Siegenni
 */

#ifndef KEYREADER_HPP_
#define KEYREADER_HPP_

#include <SFML/Graphics.hpp>

class KeyReader
{
public:
	KeyReader(int delayMilli, sf::Keyboard::Key);
	bool 				isKeyPressed();

private:
	sf::Clock			_cooldown;
	sf::Time			_elapsed;
	int					_delayMilli;
	sf::Keyboard::Key 	_key;
};

#endif /* KEYREADER_HPP_ */
