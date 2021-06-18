#include "pch.h"
#include "Player.h"
#include "Game.h"
#include "Bullet.h"

Player::Player()
{}

void Player::Start()
{
	this->player.setRadius(25.0f);
	this->player.setFillColor(Color::White);

	this->attackCooldownMax = 10.0f;
	this->attackCooldown = this->attackCooldownMax;
}

void Player::Update(Game *ourGame)
{
	playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
	mousePosWindow = Vector(Mouse::getPosition(*ourGame->window));
	aimDir = (mousePosWindow - playerCenter).Normalized();

	//cout << aimDir.x << " " << aimDir.y << "\n";

	UpdateAttack();

	if (Keyboard::isKeyPressed(Keyboard::A))
		player.move(-5.0f, 0.0f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		player.move(5.0f, 0.0f);
	if (Keyboard::isKeyPressed(Keyboard::W))
		player.move(0.0f, -5.0f);
	if (Keyboard::isKeyPressed(Keyboard::S))
		player.move(0.0f, 5.0f);

	if(Mouse::isButtonPressed(Mouse::Left) && this->CanAttack())
	{
		//cout << "Fire\n";
		ourGame->entities.emplace_back(new Bullet(player.getPosition().x, player.getPosition().y, aimDir.x, aimDir.y,  6.0f));
		//cout << ourGame->bullets.size();
	}
}

void Player::Draw(sf::RenderWindow* window)
{
	window->draw(this->player);
}

const bool Player::CanAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.0f;
		return true;
	}

	return false;
}

void Player::UpdateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

Player::~Player()
{
}
