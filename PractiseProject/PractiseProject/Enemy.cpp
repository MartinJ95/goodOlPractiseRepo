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

}

void Enemy::Draw(sf::RenderWindow* window)
{
	window->draw(this->enemy);
}

void Enemy::InitShape()
{
	this->enemy.setSize(sf::Vector2f(rand() % 80, rand() % 80));
	this->enemy.setFillColor(sf::Color::Red);
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
{
}