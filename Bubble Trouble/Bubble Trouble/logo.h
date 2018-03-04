#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Logo
{
private:
	sf::Texture logotexture;
	sf::Sprite logo;
	

public:
	Logo()
	{
		if (!logotexture.loadFromFile("logo.png"))
		{
			std::cout << "Error loading paddle texture :(" << std::endl;
		}
		logo.setTexture(logotexture);
		logo.setScale(sf::Vector2f(0.7f, 0.7f));
	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(logo);
	}

};