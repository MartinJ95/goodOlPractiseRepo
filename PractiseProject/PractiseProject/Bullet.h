#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Bullet
{
private:
	sf::CircleShape shape;

	sf::Vector2f direction;
	float movementSpeed;

public:
	Bullet();
	Bullet(float posX, float posY, float dirX, float dirY, float movementSpeed);
	virtual ~Bullet();

	const sf::FloatRect getBounds();

	void Update();
	void Render(sf::RenderTarget* target);
};

