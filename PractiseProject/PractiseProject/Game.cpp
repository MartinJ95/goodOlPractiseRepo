#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>

using namespace std;

Game::Game()
{
	this->InitPlayer();
	this->InitEnemies();
}

bool Game::Initialize()
{
	//game set up here
    this->window = nullptr;

    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new RenderWindow(this->videoMode, "Cal Engine", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);

	return true;
}

void Game::Run()
{
	//while graphics.window is open
		//game loop
	 
	this->Initialize();
}

Game::~Game()
{
    delete this->window;
}

// Accessors
const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::Update()
{
	this->PollEvents();

	this->UpdateMousePositions();

	this->UpdatePlayer();
}

void Game::UpdateMousePositions()
{
	/*
		Updates the mose positions relative to the game window
	*/

	this->mousePosWindow = Mouse::getPosition(*this->window);
}

void Game::InitPlayer()
{
	player.setRadius(25.0f);
	this->player.setFillColor(Color::White);
}

void Game::UpdatePlayer()
{
	playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
	mousePosWindow = Vector2f(Mouse::getPosition(*this->window));
	aimDir = mousePosWindow - playerCenter;
	aimDirNormalized = sqrt(pow(aimDir.x,2) + pow(aimDir.y, 2));

	cout << aimDirNormalized.x << " " << aimDirNormalized.y << "\n";
}

void Game::Render()
{	/*
		Renders the game objects
	*/
	this->window->clear();

	// Draw game objects
	this->window->draw(this->enemy);
	this->window->draw(this->player);

	// draw game objects
	this->window->display();
}

void Game::InitEnemies()
{
	this->enemy.setPosition(10.0f, 10.0f);
	this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.0f);
}

void Game::PollEvents()
{
	while (this->window->pollEvent(this->ev))
    {
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
    }
}