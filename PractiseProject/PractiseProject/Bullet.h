#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"

class Bullet : public Entity
{
private:
	sf::CircleShape shape;

	sf::Vector2f direction;
	float movementSpeed;

public:
	Bullet();
	Bullet(float posX, float posY, float dirX, float dirY, float movementSpeed);
	void Update(Game *ourGame) override;
	void Draw(sf::RenderWindow* window) override;
	virtual ~Bullet();

	const sf::FloatRect getBounds();
};