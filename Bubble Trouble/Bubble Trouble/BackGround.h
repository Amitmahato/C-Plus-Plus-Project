#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include<string>

class BackGround
{
private:
	sf::Texture bgtexture;
	sf::Texture htexture;
	sf::Sprite hsprite;
	sf::Sprite bgsprite;
	 int health=6;

public:
	BackGround()
	{
		
		if (!bgtexture.loadFromFile("bbb.jpg",sf::IntRect(500,700,1400,1000)))
		{
			std::cout << "Error loading paddle texture :(" << std::endl;
		}
		bgsprite.setTexture(bgtexture);
		//logo.setScale(sf::Vector2f(0.7f, 0.7f));
	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(bgsprite);
		window.draw(hsprite);
	}
	int animate_health();
};

int BackGround::animate_health()
{
	
	float width, height;
	if (!htexture.loadFromFile("h.png"))
	{
		std::cout << "Error loading health texture :(" << std::endl;
	}
	hsprite.setTexture(htexture);
	hsprite.setScale(0.4f, 0.4f);
	width = htexture.getSize().x/8.0;
	height = htexture.getSize().y/2.0;
	hsprite.setTextureRect(sf::IntRect(0, 0, width*(health-1) , height));
	health--;
	int temp = health;
	if (temp == 0)
		health = 6;
	std::cout << temp;
	return temp;
	
}

