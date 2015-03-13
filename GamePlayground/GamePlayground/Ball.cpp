#include "Ball.h"

Ball::Ball() {
	radius = 15;
	center = new sf::Vector2f(390.0f, 290.0f); 
	speed = 0.05f;
}

Ball::~Ball() {
	delete center;
}

float Ball::getTop() const{
	return center->y + radius;
}

float Ball::getBot() const{
	return center->y + radius;
}

float Ball::getLeft() const{
	return center->x - radius;
}

float Ball::getRight() const{
	return center->x + radius;
}

float Ball::getRadius() const {
	return radius;
}

void Ball::move() {
	sf::Vector2f movement = dest - *center;
	float i = sqrt(pow(movement.x, 2) + pow(movement.y,2));
	movement /= i;
	*center += (movement * speed);
}

void Ball::setDest(sf::Vector2f v){
	dest = v;
}

sf::Vector2f Ball::getDest() {
	return dest;
}