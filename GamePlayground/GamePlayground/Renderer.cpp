#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow* wind, const Paddle* pl1, 
				   const Paddle* pl2, const Ball* bal, const Wall* tw, const Wall* bw) {
	window = wind;

	p1 = pl1;
	p2 = pl2;
	player1.setSize(p1->getSize());
	player2.setSize(p2->getSize());
	player2.setFillColor(sf::Color::Green);
	player1.setFillColor(sf::Color::Green);

	b = bal;
	ball.setRadius(b->getRadius());
	ball.setFillColor(sf::Color::Blue);

	bo = bw;
	bottom.setPosition(bo->getPosition());
	bottom.setSize(bo->getDimens());
	bottom.setFillColor(sf::Color::Cyan);

	to = tw;
	top.setPosition(to->getPosition());
	top.setSize(to->getDimens());
	top.setFillColor(sf::Color::White);
}

Renderer::~Renderer() {
	
}

void Renderer::update() {
	player1.setPosition(p1->getfXPos(), p1->getfYPos());
	player2.setPosition(p2->getfXPos(), p2->getfYPos());
	ball.setPosition(*(b->getCenter()));

	window->clear();
	drawPaddles();
	drawBall();
	drawWalls();
	window->display();
}

void Renderer::drawPaddles() {
	window->draw(player1);
	window->draw(player2);
}

void Renderer::drawBall() {
	window->draw(ball);
}

void Renderer::drawWalls() {
	window->draw(bottom);
	window->draw(top);
}