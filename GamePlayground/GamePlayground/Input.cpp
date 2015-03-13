#include "Input.h"

Input::Input() {
	thread = new std::thread(checkInput);
}

Input::~Input() {
	delete thread;
}

void Input::synch(){
	thread->join();
}

void Input::checkInput(sf::Event e, Paddle* player) {
	if(player->getfXPos() < 400.0f){
		if (e.key.code == sf::Keyboard::W)
			player->moveUp();
		else if (e.key.code == sf::Keyboard::S)
			player->moveDown();
	}
	else
		if (e.key.code == sf::Keyboard::Up)
			player->moveUp();
		else if (e.key.code == sf::Keyboard::Down)
			player->moveDown();
}