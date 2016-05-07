#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	//this is a overloaded constructor. 
	//One that doesnt use a float and one that does
	sf::CircleShape shape2;
	shape2.setRadius(100.f);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//all our input
		//game code
		//changes
		//


		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}