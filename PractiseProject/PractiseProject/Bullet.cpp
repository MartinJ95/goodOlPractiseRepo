#include "pch.h"
#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(float posX, float posY, float dirX, float dirY, float movementSpeed)
{
	//this->shape.setTexture(*texture);
	this->shape.setRadius(10.0f);
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = movementSpeed;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds()
{
	return this->shape.getGlobalBounds();
}

void Bullet::Update()
{
	// Movement
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}