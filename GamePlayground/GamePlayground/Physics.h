#ifndef PHYSICS_H
#define PHYSICS_H

#include "Wall.h"
#include "Paddle.h"
#include "Ball.h"
#include "SFML\Graphics.hpp"

class Physics {

private:
	Ball* ball;
	Paddle* paddle1;
	Paddle* paddle2;
	Wall* top;
	Wall* bot;
	bool colTop() const;
	bool colBot() const;
	bool colP1() const;
	bool colP2() const;
	bool colB1() const;
	bool colB2() const;
	sf::Vector2f calcBallDest(Paddle* p);
	void moveBall();
	bool reset;

public:
	Physics(Ball* ball,  Paddle* paddle1,  Paddle* paddle2, 
		Wall* top,  Wall* bot);
	void start();
	void manageCollision(); 
	bool restart();
};

#endif