#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Paddle {
	
private:
	float speed, xPos, yPos, xLength, yLength, initx, inity;
	

public:
	Paddle(int x);
	~Paddle() {}
	
	void reset() {
		xPos = initx;
		yPos = inity;
	}

	int getWidth() const {
		return xLength;
	}
	int getXPos() const{
		return xPos;
	}

	int getYPos() const {
		return yPos;
	}

	float getfXPos() const{
		return (float) xPos;
	}

	float getfYPos() const {
		return (float)yPos;
	}

	void moveDown(){
		yPos += speed;
	}

	void moveUp() {
		yPos -= speed;
	}
	sf::Vector2f getCenter() const;

	sf::Vector2f getSize() const;

	sf::Vector2f getHitBox() const;
};

#endif