#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
class MartinEntity
{
public:
	MartinEntity();
	MartinEntity(sf::Vector2f position);
	virtual void Update(const float dt);
	virtual void Draw() const;
private:
	sf::Vector2f m_position;
};

class MartinGame
{
public:
	MartinGame();
	bool Intialize(float windowWidth, float windowHeight);
	void Run();
	~MartinGame();
private:
	sf::RenderWindow *m_window;
	MartinEntity m_player;
	std::vector<MartinEntity> m_entities;
	sf::Time m_time;
	float m_previousTime;
	float m_currentTime;
};

