// Created by Calum Murray, 2021

#include "pch.h"
#include "iostream"
#include "Game.h"
#include "Vector.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	Game ourGame;

	if (ourGame.Initialize() == false)
	{
		return -1;
	}

	// run the program as long as the window is open 
    while (ourGame.isRunning())
    {
		ourGame.Update();
        ourGame.Render();
    }

    return 0;
}