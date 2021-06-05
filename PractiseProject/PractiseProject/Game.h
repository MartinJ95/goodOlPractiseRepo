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
public:
	Graphics *m_graphics;
	//public variables
private:
	//private variables
};

