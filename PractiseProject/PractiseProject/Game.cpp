#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Vector.h"
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

	this->UpdatePlayer();

	this->UpdateControls();

	this->UpdateBullets();

	this->UpdateAttack();
}

void Game::InitPlayer()
{
	this->player.setRadius(25.0f);
	this->player.setFillColor(Color::White);

	this->attackCooldownMax = 10.0f;
	this->attackCooldown = this->attackCooldownMax;
}

void Game::UpdatePlayer()
{
	playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
	mousePosWindow = Vector(Mouse::getPosition(*this->window));
	aimDir = (mousePosWindow - playerCenter).Normalized();

	//cout << aimDir.x << " " << aimDir.y << "\n";
}

void Game::UpdateControls()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
		player.move(-5.0f, 0.0f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		player.move(5.0f, 0.0f);
	if (Keyboard::isKeyPressed(Keyboard::W))
		player.move(0.0f, -5.0f);
	if (Keyboard::isKeyPressed(Keyboard::S))
		player.move(0.0f, 5.0f);

	if(Mouse::isButtonPressed(Mouse::Left) && this->CanAttack())
	{
		//cout << "Fire";
		this->bullets.emplace_back(new Bullet(player.getPosition().x, player.getPosition().y, aimDir.x, aimDir.y,  5.5f));
	}
}

void Game::UpdateBullets()
{
	unsigned counter = 0;
	for (auto *bullets : this->bullets)
	{
		bullets->Update();

		// Bullet culling (top of the screen)
		if (bullets->getBounds().top + bullets->getBounds().height < 0.0f)
		{
			// Delete bullet
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Game::UpdateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

const bool Game::CanAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.0f;
		return true;
	}

	return false;
}


void Game::Render()
{	/*
		Renders the game objects
	*/
	this->window->clear();

	// Draw game objects
	this->window->draw(this->enemy);
	this->window->draw(this->player);

	for (auto *bullets : this->bullets)
	{
		bullets->Render(this->window);
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