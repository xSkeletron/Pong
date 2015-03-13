#ifndef WALL_H
#define WALL_H

#include "SFML\Graphics.hpp"

class Wall {
public:
	Wall(float x, float y);
	~Wall();

	float getInSide() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getDimens() const;

private:
	sf::Vector2f dimens;
	sf::Vector2f position;
	
};

#endif