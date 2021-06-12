#include "pch.h"
#include "MartinGame.h"


MartinEntity::MartinEntity() : m_position(sf::Vector2f(0, 0))
{
}

MartinEntity::MartinEntity(sf::Vector2f position) : m_position(position)
{
}

void MartinEntity::Update(const float dt)
{
}

void MartinEntity::Draw() const
{
}

MartinGame::MartinGame() : m_player(), m_entities(), m_time(), m_previousTime(), m_currentTime()
{
}

bool MartinGame::Intialize(float windowWidth, float windowHeight)
{
	m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "martinsPractise");
}

void MartinGame::Run()
{
	m_previousTime = m_currentTime;
	m_currentTime = m_time.asSeconds;
	m_time = m_time.Zero;
	m_player.Update(m_currentTime - m_previousTime);
	
}


MartinGame::~MartinGame()
{
}
