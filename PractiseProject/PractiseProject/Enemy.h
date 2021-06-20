#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Bullet.h"

class Enemy : public Entity
{
public:
	Enemy();

public:
	virtual ~Enemy();

	sf::RectangleShape enemy;

	void Start() override;
	void Update(Game *ourGame) override;
	void Draw(sf::RenderWindow* window) override;

	void InitEnemies();
};

