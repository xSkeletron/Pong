#ifndef INPUT_H
#define INPUT_H

#include "SFML\Graphics.hpp"
#include "Paddle.h"
#include <thread>

class Input {

public:
	Input();
	~Input();
	void checkInput(sf::Event e, Paddle* player);
	void synch();
private:
	std::thread* thread;
};


#endif