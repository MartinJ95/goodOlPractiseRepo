#pragma once
#include "Graphics.h"

using namespace sf;

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

	// mouse positons
	Vector2i mousePosWindow;

	//Game objects
	RectangleShape enemy;
	CircleShape player;

	// Player attributes
	Vector2f playerCenter;
	Vector2f aimDir;
	Vector2f aimDirNormalized;

	void InitPlayer();
	void InitEnemies();

	void UpdateMousePositions();
	void UpdatePlayer();
public:
	Graphics *m_graphics;

	const bool isRunning() const;

	void Render();
	void Update();
	void PollEvents();private:
};

