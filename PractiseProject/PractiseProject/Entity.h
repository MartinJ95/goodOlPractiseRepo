#pragma once
#include "SFML/Graphics.hpp"

class Game;

class Entity
{
public:
	Entity();
	virtual void Start();
	virtual void Update(Game* ourGame);
	virtual void Draw(sf::RenderWindow* window);
	virtual ~Entity();
	bool m_active;
};

