#pragma once
#include <iostream>
#include"loadsprite.h"
#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
class bubbles
{
    protected:
	sf::Texture bubbletexture;
	sf::Sprite bubble;
	float Vx = 1;
	float Vy = 2;
	float g = 0.2;
	float friction = 0.99;
	int var = rand() % 2 + 1;
	

	
public:
	int count = 0;
	bubbles()
	{
		if (!bubbletexture.loadFromFile("ball1.png"))
		{
			std::cout << "Error loading paddle texture :(" << std::endl;
		}

		bubble.setPosition(sf::Vector2f(rand() % 1000, -50));
		bubble.setTexture(bubbletexture);
		bubbletexture.setSmooth(true);
		bubble.setScale(0.6f, 0.6f);
		/*LoadSprite loadsprite("ball1.png");
		bubbletexture = loadsprite.ReturnTexture();
		bubble = loadsprite.ReturnSprite();*/
		

	}
	
	~bubbles()
	{
		std::cout << "destructor is called" << std::endl;
	}
	virtual void setscale(float x, float y)
	{
		bubble.setScale(sf::Vector2f(x, y));
	}

	virtual void setpos(int x, int y)
	{
		bubble.setPosition(sf::Vector2f(x, y));     
	}

	 sf::Vector2f getpos()
	{
		return (bubble.getPosition());
	}

	void update(sf::Sprite player,sf::Sprite b,sf::RenderWindow& window)
	{
		
		
		if(bubble.getPosition().y > window.getSize().y- bubble.getScale().y*bubbletexture.getSize().y/2-130 || Collision::PixelPerfectTest(player,b))
		{

			Vy = -1 * Vy*friction;
		}
		else
		{
			Vy = Vy + g;
		}
		if (bubble.getPosition().x + bubble.getScale().x*bubbletexture.getSize().x- bubble.getScale().x*bubbletexture.getSize().x/5 > window.getSize().x || bubble.getPosition().x+ bubble.getScale().x*bubbletexture.getSize().x/5  < 0)
		{
			Vx = -1 * Vx;
		}
		if(var==1)
			bubble.setPosition(sf::Vector2f(bubble.getPosition().x - Vx, bubble.getPosition().y + Vy));
		if(var==2)
			bubble.setPosition(sf::Vector2f(bubble.getPosition().x + Vx, bubble.getPosition().y + Vy));
	}
	virtual void draw(sf::RenderWindow& window)
	{
		window.draw(bubble);
	}
	

	virtual sf::Sprite bubblesprite()
	{
		return bubble;
	}
};