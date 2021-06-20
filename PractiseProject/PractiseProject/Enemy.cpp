#include "pch.h"
#include "Enemy.h"
#include "Game.h"
#include "Bullet.h"

Enemy::Enemy()
{}

void Enemy::Start()
{
	InitEnemies();
}

void Enemy::Update(Game* ourGame)
{

}

void Enemy::Draw(sf::RenderWindow* window)
{
	window->draw(this->enemy);
}

void Enemy::InitEnemies()
{
	this->enemy.setPosition(10.0f, 10.0f);
	this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.0f);
}

Enemy::~Enemy()
{
}