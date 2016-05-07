#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>


class AnimatedSprite
{

public:
	//Things we need to store
	sf::Sprite sprite;
	int currentFrame;
	float timeSinceLastChange;


	//constructor
	AnimatedSprite(sf::Texture myTexture);
	void Update(float timeSinceLastFrame);



};

int main()
{

	sf::Clock clock1;
	sf::Time elapsed1;
	float timeSinceLastFrameAsFloat = 0.0f;
	float lastTimeAsFloat = 0.0f;




	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	//this is a overloaded constructor. 
	//One that doesnt use a float and one that does
	sf::CircleShape shape2;
	shape2.setRadius(100.f);

	//
	//TEXTURES
	//
	sf::Texture fireTexture;
	if (!fireTexture.loadFromFile("FireSprite.png"))
	{
		// error
		std::cout << "GEOFF!!!!";
		return 0;
	}
	sf::Texture wallBrickTexture;
	if (!fireTexture.loadFromFile("WallBrick.png"))
	{
		// error
		std::cout << "GEOFF!!!!";
		return 0;
	}

	//
	//Sprites
	//
	AnimatedSprite animS1(fireTexture);

	sf::Sprite wallBrickSprite[2];

	for (int i = 0; i < 2; i++)
	{
		wallBrickSprite[i].setTexture(wallBrickTexture);

	};

	sf::Sprite wallBrickSpriteSolo;
	wallBrickSpriteSolo.setTexture(wallBrickTexture);
	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Timer here
		elapsed1 = clock1.getElapsedTime();
		timeSinceLastFrameAsFloat = elapsed1.asSeconds() - lastTimeAsFloat;
		lastTimeAsFloat = elapsed1.asSeconds();
		//std::cout << timeSinceLastFrameAsFloat << "seconds\n";

		//Updates for the sprites we have
		animS1.Update(timeSinceLastFrameAsFloat);

		//all our input
		//game code
		//changes
		//


		window.clear();
		window.draw(shape);
		//window.draw(animS1.sprite);
		//window.draw(testSprite);
		/*
		for (int i = 0; i < 2; i++)
		{
			window.draw(wallBrickSprite[i]);
		};
		*/
		window.draw(wallBrickSpriteSolo);

		window.display();
	}

	return 0;
}

AnimatedSprite::AnimatedSprite(sf::Texture myTexture) { //no void for contstrctpr
	currentFrame = 0;
	timeSinceLastChange = 0.0f;

	sprite.setTexture(myTexture);
	sprite.setTextureRect(sf::IntRect(64 * currentFrame, 0, 64, 64));
	

}

void AnimatedSprite::Update(float timeSinceLastFrame) {

	timeSinceLastChange += timeSinceLastFrame;
	if (timeSinceLastChange >= 0.25f) {

		std::cout << "timer hits 0.25 seconds\n";
		timeSinceLastChange = 0.0f; //reset the timer

		//increment the frame counter
		if (currentFrame >= 3) {
			currentFrame = 0;
		}
		else {
			currentFrame++;
		}

		//change the section of the texture
		sprite.setTextureRect(sf::IntRect(64 * currentFrame, 0, 64, 64));
	}



}
