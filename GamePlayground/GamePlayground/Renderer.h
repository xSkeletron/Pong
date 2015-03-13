#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"

class Renderer {

private:
	const Paddle* p1;
	const Paddle* p2;
	const Ball* b;
	const Wall* bo;
	const Wall* to;
	sf::RectangleShape player1;
	sf::RectangleShape player2;
	sf::CircleShape ball;
	sf::RectangleShape bottom;
	sf::RectangleShape top;
	sf::RenderWindow* window;
	void drawBall();
	void drawPaddles();
	void drawWalls();

public:
	Renderer(sf::RenderWindow* wind, const Paddle* pl1, const Paddle* pl2, 
		const Ball* bal, const Wall* wal, const Wall* wal2);
	~Renderer();
	void update();
};

#endif