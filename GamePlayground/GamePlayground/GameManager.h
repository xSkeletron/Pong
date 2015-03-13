#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Renderer.h"
#include "Paddle.h"
#include "Physics.h"
#include "Ball.h"

class GameManager {

private:
	bool running;
	Paddle* player1;
	Paddle* player2;
	Physics* phy;
	Renderer* art;
	sf::RenderWindow* window;
	Ball* ball;
	Wall* bottom;
	Wall* top;
public:
	GameManager();
	~GameManager();
	void runGame();

};

#endif