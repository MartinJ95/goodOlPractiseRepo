// PractiseProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "iostream"
#include "Game.h"
#include "Vector.h"
#include <SFML/Graphics.hpp>

using namespace std;

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

    Point p;
    p.x = 0;
    p.y = -1;

    Point i;
    i.x = 1;
    i.y= 1;

    Point c;
    c.x = 2;
    c.y = -1;

    Vector cp;
    Vector ip;

    cp = p - c;
    ip = p - i;

    float length_sqr_cp = cp.LengthSqr();
    float length_sqr_ip = ip.LengthSqr();

    cout << "Length sqr of CP: " << length_sqr_cp << "\n";
    cout << "Lenght sqr of IP: " << length_sqr_ip << "\n";

	// create the window
    sf::RenderWindow window(sf::VideoMode(640, 480), "Cal Engine");

    sf::CircleShape circle(100);

    //circle.setRadius(40);
    //circle.setPointCount(15);

    //circle.setFillColor(sf::Color(255, 0 , 0));
    //circle.setOutlineColor(sf::Color(0,255,0));
    //circle.setOutlineThickness(-2);

    sf::Texture texture;

    if (!texture.loadFromFile("Resources/Images/Bricks.jpg"))
    {
        cout << "Load failed" << endl;

        system("pause");

        return EXIT_FAILURE;
    }

    circle.setTexture(&texture);
    circle.setTextureRect(sf::IntRect(0,0,500,500));

    sf::RectangleShape rectangle(sf::Vector2f(100,60));

    rectangle.setSize(sf::Vector2f(500,400));

    rectangle.setTexture(&texture);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(rectangle);

        // end the current frame
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