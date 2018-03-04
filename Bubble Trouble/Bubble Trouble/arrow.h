#pragma once
#include <iostream>
#include"loadsprite.h"
#include <SFML/Graphics.hpp>
class Bullet
{
private:
	sf::Texture bullettexture;
	std::vector<sf::Sprite> bullets;
	sf::Sprite bullet;
	int shootertime = 0;
	sf::Sprite ithbullet;
	sf::Sound sound;
	sf::SoundBuffer buffer;

public:
	Bullet()
	{
		
		if (!buffer.loadFromFile("Arrow_Swoosh_2.ogg"))
			std::cout << "couldnt load the sound" << std::endl;
		
		sound.setBuffer(buffer);
		sound.setVolume(30);
		//bullet.setPosition(sf::Vector2f(800 / 2 +20, 600 / 2 - 90));
		if (!bullettexture.loadFromFile("arrow.png"))
		{
			std::cout << "errorrrr!!" << std::endl;
		}
		bullet.setTexture(bullettexture);
		bullet.setScale(0.058f, 0.058f);
	}
	~Bullet()
	{

	}

	void update(float x, float y, sf::RenderWindow& window)
	{
		if (shootertime < 25)
			shootertime++;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && shootertime >= 25)
		{
			sound.play();
			bullets.push_back(bullet);
			
			shootertime = 0;
		}

		for (int i = 0; i < bullets.size(); i++)
		{ 
			bullets[i].move(0.f, -10.f);
			ithbullet = sf::Sprite(bullets[i]);
			
			if (bullets[i].getPosition().y < -100)
				bullets.erase(bullets.begin() + i);

		}
		

		bullet.setPosition(sf::Vector2f(x + 20, y - 90));


		for (int i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}

	}
	sf::Sprite returnsprite()
	{
		return ithbullet;
	}

};

