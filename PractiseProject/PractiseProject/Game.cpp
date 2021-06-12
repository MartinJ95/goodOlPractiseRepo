#include "pch.h"
#include "Game.h"
#include <SFML/Graphics.hpp>


Game::Game()
{

}

bool Game::Initialize()
{
	//game set up here
    this->window = nullptr;

    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new sf::RenderWindow(this->videoMode, "Cal Engine", sf::Style::Titlebar | sf::Style::Close);

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
	this->window->clear(sf::Color(255, 0, 0, 255));

	// draw game objects
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