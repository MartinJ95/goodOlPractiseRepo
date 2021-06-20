#pragma once
#include "Entity.h"
#include "Vector.h"
#include <vector>
#include "Bullet.h"
#include "Graphics.h"

class Player : public Entity
{
public:
	Player();

	void Start() override;
	void Update(Game *ourGame) override;
	void Draw(sf::RenderWindow* window) override;

	const bool CanAttack();
	void UpdateAttack();
	virtual ~Player();

public:
	sf::CircleShape player;

private:
	// Vectors
	Vector mousePosWindow;
	Vector playerCenter;
	Vector aimDir;

	float attackCooldown;
	float attackCooldownMax;
};

