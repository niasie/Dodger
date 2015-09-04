/*
 * game.hpp
 *
 *  Created on: 08.11.2014
 *      Author: Siegenni
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "enemy.hpp"
#include "Player.hpp"
#include "Explosion.h"
#include <vector>
#include <string>
#include <SFML/System.hpp>
#include "keyReader.hpp"

class Game
{
public:
	Game();

private:
	void 						tick();
	void 						getKeys();

	sf::RenderWindow 			_window;
	Player 						_myPlayer;
	std::vector<Enemy>			_enemies;
	std::vector<Entity> 		_bullets;
	std::vector<sf::Texture> 	_textures;
	std::vector<Explosion>		_explosions;
	KeyReader					_keySpace, _keyE;
};


#endif /* GAME_HPP_ */
