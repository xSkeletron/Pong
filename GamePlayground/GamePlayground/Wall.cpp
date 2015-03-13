#include "Wall.h"

Wall::Wall(float x, float y) {
	position.x = x;
	position.y = y;
	dimens.x = 800;
	dimens.y = 5;
}

Wall::~Wall() {

}

float Wall::getInSide()  const {
	if(position.y < 400)
		return position.y + dimens.y;
	else
		return position.y;
}

sf::Vector2f Wall::getPosition() const {
	return position;
}

sf::Vector2f Wall::getDimens() const {
	return dimens;
}