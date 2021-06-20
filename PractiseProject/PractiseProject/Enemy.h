#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Bullet.h"

class Enemy : public Entity
{
public:
	Enemy(float posX, float posY);

public:
	virtual ~Enemy();

	void Start() override;
	void Update(Game *ourGame) override;
	void Draw(sf::RenderWindow* window) override;

private:
	sf::RectangleShape enemy;
	int type;
	int health;
	int maxHealth;
	int damage;
	int points;

	void InitShape();
	void InitVariables();
};

