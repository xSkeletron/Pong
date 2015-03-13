#include "Paddle.h"

Paddle::Paddle(int x) {
	xPos = initx = x;
	yPos = inity = 275;
	speed = 5;
	xLength = 20;
	yLength = 100;
}

sf::Vector2f Paddle::getHitBox() const {
	sf::Vector2f hit((float) yPos, (float) (yPos + yLength));
	return hit;
}

sf::Vector2f Paddle::getSize() const {
	sf::Vector2f size((float)xLength, (float)yLength);
	return size;
}

sf::Vector2f Paddle::getCenter() const {
	sf::Vector2f vector(0.0f, 0.0f);
	float midx = xPos + xLength/2;
	float midy = yPos + yLength/2;
	vector.x = midx;
	vector.y = midy;

	return vector;
}