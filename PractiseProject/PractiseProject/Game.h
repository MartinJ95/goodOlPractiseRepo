#pragma once
#include "Graphics.h"

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
    sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
public:
	Graphics *m_graphics;
	const bool isRunning() const;
	void Render();
	void Update();
	void PollEvents();
private:
	//private variables
};

