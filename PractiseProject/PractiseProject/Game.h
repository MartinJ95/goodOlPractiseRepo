#pragma once
#include "Graphics.h"
#include "Vector.h"
#include "Entity.h"

using namespace sf;
using namespace std;

class Bullet;

class Game
{
public:
	Game();
	bool Initialize();
	void Run();
	~Game();

private: 
	//private functions
		// create the window

	VideoMode videoMode;
	Event ev;

	// Game objects
	RectangleShape enemy;

	// Functions
	void InitEnemies();

public:
	RenderWindow* window;
	Graphics *m_graphics;

	std::vector<Bullet*> bullets;
	vector<Entity*> entities;

	const bool isRunning() const;

	void Render();
	void Update();
	void PollEvents();
};

