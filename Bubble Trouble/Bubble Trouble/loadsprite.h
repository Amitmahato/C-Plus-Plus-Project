#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include<string>

class LoadSprite
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	
	LoadSprite(std::string s)
	{
		if (!texture.loadFromFile(s))
		{
			std::cout << "Error loading paddle texture :(" << std::endl;
		}
		sprite.setTexture(texture);
		std::cout << s << std::endl;
	}

	sf::Texture ReturnTexture()
	{
		return texture;
	}

	sf::Sprite ReturnSprite()	
	{
		return sprite;
	}

};