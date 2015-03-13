#include "Physics.h"
#include <iostream>

Physics::Physics(Ball* b, Paddle* p1,  Paddle* p2, 
		 Wall* t,  Wall* bo) {
	ball = b;
	paddle1 = p1;
	paddle2 = p2;
	top = t;
	bot = bo;
	reset = false;
}

void Physics::start() {
	reset = false;
	sf::Vector2f ballDest(0.0f, 10.0f);
	if(rand() % 2)
		ballDest.x = 900.0f;
	ballDest.y = rand() % 300;
	ball->setDest(ballDest);
	
}

void Physics::moveBall() {
	
	ball->move();
}

bool Physics::colTop()  const {
	return (ball->getCenter()->y - ball->getRadius()) < top->getInSide();
}

bool Physics::colBot()  const {
	return (ball->getCenter()->y + ball->getRadius()) > bot->getInSide();
}

bool Physics::colP1()  const {
	sf::Vector2f hit = paddle1->getHitBox();
	if (ball->getLeft() < paddle1->getfXPos()){
		return(ball->getCenter()->y > hit.x) && (ball->getCenter()->y < hit.y);
	}
	else
		return false;
}

bool Physics::colP2()  const {
	sf::Vector2f hit = paddle2->getHitBox();
	if ((ball->getRight()) > paddle2->getfXPos())
		return(ball->getCenter()->y > hit.x) && (ball->getCenter()->y < hit.y);
	else
		return false;
}

bool Physics::colB1() const {
	return (ball->getLeft()) < 0.5f;
}

bool Physics::colB2() const {
	return (ball->getRight()) > 799.5f;
}

void Physics::manageCollision(){
	if(colP1()){
		std::cout << "p1" << std::endl;
			std::cout << ball->getLeft() << std::endl;
		sf::Vector2f dest = calcBallDest(paddle1);
		ball->setDest(dest);
	} 
	else if(colP2()){
		std::cout << "p2" << std::endl;
			std::cout << ball->getRight() << std::endl;
		sf::Vector2f dest = calcBallDest(paddle2);
		ball->setDest(dest);
	} 
	else if(colTop() || colBot())
	{
		sf::Vector2f* dest = new sf::Vector2f(ball->getDest().x, -ball->getDest().y);
		ball->setDest(*dest);
		delete dest;
	}
	else if(colB1() || colB2())
	{
		sf::Vector2f* dest = new sf::Vector2f(-ball->getDest().x, ball->getDest().y);
		ball->setDest(*dest);
		delete dest;
		reset = true;
	}

	moveBall();
}

sf::Vector2f Physics::calcBallDest(Paddle* p) {
	sf::Vector2f dest = ball->getDest();
			dest.x *= -1;
	if(ball->getCenter()->y <= p->getCenter().y) 
		dest.y = rand() % 300;
	else
		dest.y = rand() % 300 + 300;

	return dest;
}

bool Physics::restart() {
		if(reset){
			ball->reset();
			paddle1->reset();
			paddle2->reset();
			reset = false;
			return true;
		}
		return false;
}