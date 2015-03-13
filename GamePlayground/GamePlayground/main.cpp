#include <iostream>

#include "GameManager.h"



int main()
{

	/*sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->draw(shape);
        window->display();
    }

    return 0;*/
	
	GameManager manager;
	manager.runGame();


	//sf::TcpSocket socket;
	//sf::Socket::Status status = socket.connect("174.77.54.219", 1104);
	//if (status != sf::Socket::Done)
	//{
	//	std::cout << "couldn't connect!" << std::endl;
	//}
	//else 
	//{
	//	
	//	std::string role;
	//	char name[100];
	//	role = "k";

	//	std::cout << "who would you like to kill?" << std::endl;
	//	std::cin >> name;
	//	sf::Packet packet;

	//	packet << name << role;

	//	//// tcp socket:
	//	//if (socket.send(data, 100) != sf::socket::done)
	//	//{
	//	//	std::cout << "nothing sent d:" << std::endl;
	//	//}

	//	socket.send(packet);
	//		
	//	std::cin.get();
	//}


	return 0;
}
