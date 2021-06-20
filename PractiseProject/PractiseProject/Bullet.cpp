#include "pch.h"
#include "Bullet.h"

Bullet::Bullet()
{}

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

void Bullet::Update(Game *ourGame)
{
	// Movement
	this->shape.move(this->movementSpeed * this->direction);

	if(shape.getGlobalBounds().top + shape.getGlobalBounds().height < 0.0f)
	{
		m_active = false;
	}

	//unsigned counter = 0;
	//for (auto *bullets : bullets)
	//{
	//	bullets->Update();

	//	// Bullet culling (top of the screen)
	//	if (bullets->getBounds().top + bullets->getBounds().height < 0.0f)
	//	{
	//		// Delete bullet
	//		bullets.erase(bullets.begin() + counter);
	//		--counter;
	//	}

	//	++counter;
	//}
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds()
{
	return this->shape.getGlobalBounds();
}

void Bullet::Draw(sf::RenderWindow* window)
{
	window->draw(this->shape);
}