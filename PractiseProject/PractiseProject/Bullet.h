#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet
{
public:
	CircleShape shape;
	Vector2f currentVelocity;
	float maxSpeed;

	Bullet(float radious = 5.0f) : currentVelocity(0.0f, 0.0f), maxSpeed(15.0f)
	{
		this->shape.setRadius(radious);
		this->shape.setFillColor(Color::Red);
	};

};

