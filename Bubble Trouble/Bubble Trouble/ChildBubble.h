#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include"bubble.h"

class ChildBubbble : public bubbles
{
private:
	//sf::Sprite bubble;

public:
	ChildBubbble()
	{
		std::cout << "in constructor" << std::endl;
		bubbles();
	}

	/*void draw(sf::RenderWindow& window)
	{
		std::cout << "in draw" << std::endl;
		window.draw(bubble);
	}*/

};
void newbubble()
{
	ChildBubbble child1;
	child1.setscale(0.5f, 0.5f);


}