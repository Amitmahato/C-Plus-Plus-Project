#pragma once
#include<SFML\Graphics.hpp>
#define menu_elements 6

class Menu
{
public:

	Menu(float width, float height);
	void draw(sf::RenderWindow &window);
	void moveup();
	void movedown();
	int getpressed_item();
	void load_menu(sf::RenderWindow &window);
private:

	int selected_item;
	sf::Font font;
	sf::Text menu[menu_elements];

};

