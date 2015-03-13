#ifndef BALL_H
#define BALL_H

#include "SFML\Graphics.hpp"

class Ball {

public:
	Ball();
	~Ball();

	float getTop() const;
	float getBot() const;
	float getLeft() const;
	float getRight() const;
	float getRadius() const;
	sf::Vector2f* getCenter() const {return center;}
	//void setCenter(sf::Vector2f vec);
	void setDest(sf::Vector2f v);
	sf::Vector2f getDest();

	void move();
	void reset() {
		center->x = 390.0f;
		center->y = 290.0f;
	}

private:
	float radius;
	float speed;
	sf::Vector2f* center;
	sf::Vector2f dest;
};

#endif