#pragma once
#include "Graphics.h"
#include "Vector.h"

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
    RenderWindow* window;
	VideoMode videoMode;
	Event ev;

	// Game objects
	RectangleShape enemy;
	CircleShape player;

	// Vectors
	Vector mousePosWindow;
	Vector playerCenter;
	Vector aimDir;
	Vector aimDirNorm;

	vector<Bullet*> bullets;


	float attackCooldown;
	float attackCooldownMax;

	// Functions
	void InitPlayer();
	void InitEnemies();

	void UpdatePlayer();
	void UpdateControls();
	void UpdateBullets();

public:
	Graphics *m_graphics;

	const bool isRunning() const;

	void Render();
	void Update();
	void PollEvents();

	void UpdateAttack();
	const bool CanAttack();
};

