#include "pch.h"
#include "Enemy.h"
#include "Game.h"
#include "Bullet.h"

Enemy::Enemy(float posX, float posY)
{
	this->enemy.setPosition(posX, posY);
}

void Enemy::Start()
{
	InitShape();
	InitVariables();
}

void Enemy::Update(Game* ourGame)
{
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		ourGame->enemies.push_back(new Enemy(rand() % 200, rand() % 200));
		this->spawnTimer = 0.f;
	}
}

void Enemy::Draw(sf::RenderWindow* window)
{
	window->draw(this->enemy);
}

void Enemy::InitShape()
{
	this->enemy.setSize(sf::Vector2f(rand() % 80, rand() % 80));
	this->enemy.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));

	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Enemy::InitVariables()
{
	this->type = 0;
	this->health = 10;
	this->maxHealth = 0;
	this->damage = 1;
	this->points = 5;
}

Enemy::~Enemy()
{}