#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet();
	sf::Vector2f velocity;
	sf::RectangleShape bullet;
	float maxSpeed;

};

class KnifeBullet
{
public:
	KnifeBullet();
	sf::Vector2f velocity;
	sf::RectangleShape bullet;
	float maxSpeed;
};

#endif // Bullet_H