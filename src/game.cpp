/*
 * game.cpp
 *
 *  Created on: 08.11.2014
 *      Author: Siegenni
 */

#include "game.hpp"
#include <math.h>
#include <iostream>
#include "Menupoint.hpp"
#include "Explosion.h"

#ifdef _WIN32
#include "direntWin.h"
#else
#include <dirent.h>
#endif

Game::Game()
   : _window(sf::VideoMode(1280, 720), "dodger", sf::Style::Close | sf::Style::Titlebar),
   _myPlayer(500, 500),
   _enemies(),
   _bullets(),
   _textures(),
   _explosions(),
   _keySpace(500, sf::Keyboard::Space),
   _keyE(50, sf::Keyboard::E)
{
	srand(time(0));

	_window.setVerticalSyncEnabled(true);

	// Imports all files in folder "res" into the _textures vector using dirent.h
	// Thanks to user "Alex" on StackOverflow for the code
	// http://stackoverflow.com/questions/67273/how-do-you-iterate-through-every-file-directory-recursively-in-standard-c
	struct dirent *entry;
	DIR *dp;

	dp = opendir("res/textures");
	if (dp == NULL) {
	    perror("opendir: Path does not exist or could not be read.");
	}

	while ((entry = readdir(dp)))
	{
		puts(entry->d_name);

		sf::Texture tempTex;
		if ((std::string(entry->d_name) != ".") && (std::string(entry->d_name) != ".."))
		{
			tempTex.loadFromFile(std::string("res/textures/") + std::string(entry->d_name));
			_textures.push_back(tempTex);
		}
	}
	closedir(dp);

	_myPlayer.setTexture(_textures.at(2));

	tick();
}

void Game::tick()
{
	sf::Clock loopTimer, enemyTimer, timeSinceStarted;
	sf::Time elapsed;
	const int loopsPerSec = 30;
	float enemiesPerSecond = 0.2;

	while (_window.isOpen())
	{
		sf::Event event;
	    while (_window.pollEvent(event))
	    {
	        if (event.type == sf::Event::Closed)
	        _window.close();
	    }

	    elapsed = loopTimer.getElapsedTime();
	    if (elapsed.asMilliseconds() > (1000 / loopsPerSec))
	    {
	        getKeys();

	        _myPlayer.update(_window);

	        for (std::vector<Explosion>::iterator p = _explosions.begin(); p != _explosions.end();)
	        {
	        	if (p->isAnimFinished() == true)
	        	{
	        		_explosions.erase(p);
	        	}
	        	else
	        	{
	        		p->update();

	        		++p;
	        	}
	        }

	        for (std::vector<Enemy>::iterator p = _enemies.begin(); p != _enemies.end();)
	        {
	        	if (p->getPosition().y > (int) _window.getSize().y)
	        	{
	        		_enemies.erase(p);
	        	}
	        	else
	        	{
	        		p->update();

	        		++p;
	        	}
	        }

	        std::vector<Entity> toBeDeleted;
	        for (std::vector<Entity>::iterator i = _bullets.begin(); i != _bullets.end();)
	        {
	        	int forwardHowOften = 1;

	        	if (i->getPosition().y < 0)
	        	{
	        		_bullets.erase(i);
	        	}
	        	else
	        	{
	        		i->setPositionRel(0, -5);

	        		for (std::vector<Enemy>::iterator e = _enemies.begin(); e != _enemies.end();)
	        		{
	        			if (e->getSprite().getGlobalBounds().intersects(i->getSprite().getGlobalBounds()))
	        			{
	        				_explosions.push_back(Explosion(sf::Vector2f(e->getPosition().x + e->getSize().x / 2, e->getPosition().y + e->getSize().y / 2), _textures.at(4), (_textures.at(4).getSize().y / _textures.at(1).getSize().y) * 1.75));

	        				e = _enemies.erase(e);
	        			}
	        			else
	        			{
	        				++e;
	        				// ++i;
	        			}
	        		}

	        		++i;
	        	}
	        }



	        elapsed = enemyTimer.getElapsedTime();
	        if (enemiesPerSecond < 1) enemiesPerSecond = 0.01 * timeSinceStarted.getElapsedTime().asSeconds() + 0.5;
	        if (elapsed.asMilliseconds() > (1000 / enemiesPerSecond))
	        {
	        	_enemies.push_back(Enemy(_textures.at(1), rand() % _window.getSize().x, -48));
	        	_enemies.at(_enemies.size()-1).setMovementSpeed(rand() % 5);

	        	enemyTimer.restart();
	        }

	        loopTimer.restart();
	    }

	    _window.clear();
	    _myPlayer.draw(_window);

	    for (std::vector<Enemy>::iterator p = _enemies.begin(); p != _enemies.end(); p++)
	    {
	    	p->draw(_window);
	    }

	    for (std::vector<Entity>::iterator p = _bullets.begin(); p != _bullets.end(); p++)
	    {
	    	p->draw(_window);
	    }

	    for (std::vector<Explosion>::iterator p = _explosions.begin(); p != _explosions.end(); p++)
	    {
	    	p->draw(_window);
	    }

	    _window.display();

	}
}

void Game::getKeys()
{
	if (_keySpace.isKeyPressed())
		_bullets.push_back(Entity("bullet", _textures.at(0), _myPlayer.getPosition().x + _myPlayer.getSize().x / 2 - _textures.at(1).getSize().x / 2, _myPlayer.getPosition().y));

	if (_keyE.isKeyPressed())
		_explosions.push_back(Explosion(sf::Vector2f(400, 400), _textures.at(4), 1));
}
