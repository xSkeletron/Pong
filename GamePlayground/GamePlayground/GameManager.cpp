#include "GameManager.h"

#include <iostream>
using namespace std;


GameManager::GameManager() {
	running = false;
	player1 = new Paddle(20);
	player2 = new Paddle(760);
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "My window");
	ball = new Ball();
	bottom = new Wall(0, 580);
	top = new Wall(0, 15);
	art = new Renderer(window, player1, player2, ball, top, bottom);
	phy = new Physics(ball, player1, player2, top, bottom);
}

GameManager::~GameManager() {
	delete art;
	delete window;
	delete player2;
	delete player1;
	delete ball;
	delete bottom;
	delete top;
	delete phy;
}

void GameManager::runGame() {

	phy->start();

	while (window->isOpen())
    {
			sf::Event event;
			
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
				if(!running && event.key.code == sf::Keyboard::Space)
					running = true;
				else
				{
					if (event.type ==sf::Event::KeyPressed)
					{
						// Player1 controls
						if (event.key.code == sf::Keyboard::W)
							player1->moveUp();
						else if (event.key.code == sf::Keyboard::S)
							player1->moveDown();
				
						// Player2 controls
						if (event.key.code == sf::Keyboard::Up)
							player2->moveUp();
						else if(event.key.code == sf::Keyboard::Down)
							player2->moveDown();
					}
				}
			}
			if(running){
				art->update();
				phy->manageCollision();
			}
			if(phy->restart() && running){
				art->update();
				running = false;
				cout << "reset"<< endl;
			}	
	}
}