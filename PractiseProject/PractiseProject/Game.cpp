#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Vector.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>

using namespace std;

Game::Game()
{
	this->InitEnemies();
}

bool Game::Initialize()
{
	//game set up here
	// Entities here
	entities.emplace_back(new Player());

	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->Start();
	}
	
    this->window = nullptr;

    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new RenderWindow(this->videoMode, "Calum's Engine", sf::Style::Titlebar | sf::Style::Close);

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
}

void Game::Render()
{	/*
		Renders the game objects
	*/
	this->window->clear();

	// Draw game objects
	this->window->draw(this->enemy);

	for(int i = 0; i < entities.size(); i++)
	{
		entities[i]->Update(this);
		entities[i]->Draw(window);
	}
	
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