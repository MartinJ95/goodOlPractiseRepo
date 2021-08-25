#pragma once
#include "Graphics.h"
#include "Vector.h"
#include "Entity.h"

using namespace sf;
using namespace std;

class Bullet;
class Enemy;

class Game
{
public:
	Game();
	bool Initialize();
	void Run();
	~Game();

public:
	RenderWindow* window;
	Graphics *m_graphics;

	vector<Bullet*> bullets;
	vector<Enemy*> enemies;
	vector<Entity*> entities;

public:
	const bool isRunning() const;

	void Render();
	void Update();
	void PollEvents();

private:
	VideoMode videoMode;
	Event ev;

private:
	void SetUpWindow();
};

