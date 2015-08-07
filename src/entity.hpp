/*
 * entity.hpp
 *
 *  Created on: 09.10.2014
 *      Author: Niall
 */

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	explicit 			Entity(std::string name, sf::Texture& tex, int x, int y);
	explicit 			Entity(std::string name, std::string pathToTex, int x, int y);
	explicit 			Entity(int x, int y);

	void 	    		update();
	void				draw(sf::RenderWindow& window);

	void 				setPosition(int x, int y) { _pos = { x, y }; }
	void 				setPositionRel(int x, int y);
	void 				setSize(int x, int y) { _size = { x, y }; }
	void 				setMovementSpeed(int speed) { _movementSpeed = speed; }
	void 				setScale(float scale) { _scale = scale; }
	void				setTexture(sf::Texture& tex);

	sf::Vector2i	 	getPosition() { return _pos; }
	sf::Vector2i		getSize() { return _size; }
	int 				getMovementSpeed() { return _movementSpeed; }
	sf::Sprite& 		getSprite() { return _sprite; }
	sf::Texture&		getTexture() { return _texture; }
	float				getScale() { return _scale; }


protected:
	int 				_movementSpeed = 1;
	sf::Vector2i		_pos, _size;
	sf::Sprite 			_sprite;

private:
	float 				_scale;
	std::string 		_name, _pathToTex;
	sf::Texture			_texture;
};

#endif /* ENTITY_HPP_ */
