#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
class players
{
private:
	sf::Texture playertexture;
	sf::Sprite player;
	sf::RectangleShape shape;
	sf::Event event;
	bool walking = true;
	bool right = false;
	bool left = false;
	bool idle = true;
	sf::Clock clock;
	sf::Time prevTime;
	const int sizeofwalkingframe = 9;
	int index = 0;
	const sf::Vector2u walkLeft[9] = {
		sf::Vector2u(0,9),
		sf::Vector2u(1,9),
		sf::Vector2u(2,9),
		sf::Vector2u(3,9),
		sf::Vector2u(4,9),
		sf::Vector2u(5,9),
		sf::Vector2u(6,9),
		sf::Vector2u(7,9),
		sf::Vector2u(8,9)
	};
	const sf::Vector2u walkRight[9] = {
		sf::Vector2u(0,11),
		sf::Vector2u(1,11),
		sf::Vector2u(2,11),
		sf::Vector2u(3,11),
		sf::Vector2u(4,11),
		sf::Vector2u(5,11),
		sf::Vector2u(6,11),
		sf::Vector2u(7,11),
		sf::Vector2u(8,11)
	};
public:

	players()
	{
		if (!playertexture.loadFromFile("player.png"))
		{
			std::cout << "Error loading paddle texture :(" << std::endl;
		}

		//	shape.setSize(sf::Vector2f(550, 550));
		shape.setTexture(&playertexture);
		player.setTexture(playertexture);
		sf::Vector2u texturesize = playertexture.getSize();
		texturesize.x /= 13;
		texturesize.y /= 21;
		sf::Vector2u idlepose = sf::Vector2u(0, 10);
		player.setTextureRect(sf::IntRect(0, 0, texturesize.x, texturesize.y));

	}

	void setpos(int x, const int y) {
		player.setPosition(sf::Vector2f(x, y));           //250,250
	}

	sf::Vector2f getpos()
	{
		return (player.getPosition());
	}

	void color(int x, int y, int z)
	{
		player.setColor(sf::Color(x, y, z));
		//player.setFillColor(sf::Color(x, y, z));
	}

	sf::Sprite returnsprite()
	{
		return player;
	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(player);

	}
	void update() {
		handleevents();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			walking = true;
			right = true;
			left = false;
			idle = false;
			player.move(2.5, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			walking = true;
			left = true;
			right = false;
			idle = false;
			player.move(-2.5, 0);
		}
		else {
			walking = false;
			idle = true;

			index = 0;
		}
	}

	void handleevents() {
		sf::Vector2u texturesize = playertexture.getSize();        //why need these here??
		texturesize.x /= 13;
		texturesize.y /= 21;
		sf::Vector2u idlepose = sf::Vector2u(0, 10);
		if (idle)
			player.setTextureRect(sf::IntRect(idlepose.x*texturesize.x, idlepose.y*texturesize.y, texturesize.x, texturesize.y));

		if (walking) {
			sf::Time newTime = clock.getElapsedTime();
			int deltaTime = newTime.asMilliseconds() - prevTime.asMilliseconds();

			if (deltaTime > 80) {
				index++;
				prevTime = newTime;
			}
			if (right) {
				player.setTextureRect(sf::IntRect(walkRight[index].x*texturesize.x, walkRight[index].y*texturesize.y, texturesize.x, texturesize.y));
			}
			if (left) {
				player.setTextureRect(sf::IntRect(walkLeft[index].x*texturesize.x, walkLeft[index].y*texturesize.y, texturesize.x, texturesize.y));
			}
			if (index >= sizeofwalkingframe)
				index = 0;
		}
	}
};