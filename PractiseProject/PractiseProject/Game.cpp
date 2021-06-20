#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Vector.h"
#include "Bullet.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

using namespace std;

Game::Game()
{}

bool Game::Initialize()
{
	// Entities here
	entities.emplace_back(new Player());
	entities.emplace_back(new Enemy());

	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->Start();
	}

	SetUpWindow();

	return true;
}

void Game::Run()
{	 
	this->Initialize();
}

Game::~Game()
{
    delete this->window;
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::Update()
{
	this->PollEvents();
}

void Game::SetUpWindow()
{
	this->window = nullptr;

    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new RenderWindow(this->videoMode, "Calum's Engine", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::Render()
{	/*
		Renders the game objects
	*/
	this->window->clear();

	for(int i = 0; i < entities.size(); i++)
	{
		entities[i]->Update(this);
		entities[i]->Draw(window);
	}
	
	this->window->display();
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