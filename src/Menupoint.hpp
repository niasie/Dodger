/*
 * Menupoint.hpp
 *
 *  Created on: 02.08.2015
 *      Author: Siegenni
 */

#ifndef MENUPOINT_HPP_
#define MENUPOINT_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Menupoint
{
	public:
		Menupoint(std::string, sf::Vector2i, sf::Font&);
		void update(sf::Window&);
		void draw(sf::RenderWindow&);

	private:
		sf::Text _text;
		sf::Vector2i _pos;
};


Menupoint::Menupoint(std::string text, sf::Vector2i pos, sf::Font& font)
{
	_text.setFont(font);
	_text.setString(text);
	_text.setCharacterSize(100);
	_text.setPosition((sf::Vector2f) pos);
	_text.setColor(sf::Color::White);
	_pos = pos;
}

void Menupoint::update(sf::Window& window)
{
	if	(_pos.x <= sf::Mouse::getPosition(window).x &&
	   	 _pos.x + _text.getLocalBounds().width >= sf::Mouse::getPosition(window).x &&
	   	 _pos.y <= sf::Mouse::getPosition(window).y &&
	   	 _pos.y + _text.getLocalBounds().height >= sf::Mouse::getPosition(window).y)
		_text.setColor(sf::Color::Blue);
	else
		_text.setColor(sf::Color::White);
}

void Menupoint::draw(sf::RenderWindow& window)
{
	window.draw(_text);
}

#endif /* MENUPOINT_HPP_ */
