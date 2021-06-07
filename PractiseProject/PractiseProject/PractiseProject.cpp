// PractiseProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>

int main()
{
	/*
	std::cout << "Hello World!\n";
	Game ourGame;
	if (ourGame.Initialize() == false)
	{
		return -1;
	}
	ourGame.Run();
	*/

	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(250.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

/*
our first step shall be to link and include the SFML library,
this can be done via dynamic or static linking (both methods are almost the same to do apart from like one difference in the process)
https://www.sfml-dev.org/tutorials/2.5/start-vc.php

we shall also start off fairly simple with the game class, graphics class and entity class. i have also made a player class inheriting off the entity class.
first goal would be to get a window up and have something showing, then to have a player moving around the screen. after that you can branch out your options a lot more.
do anything you like with entities, enemies, obstacles whatever you like my dude
*/