#pragma once
#include<SFML/Graphics.hpp>
#define retry_element 3

class Quit
{
public:
	Quit(float width, float height);
	void load_quit();
	void moveleft();
	void moveright();
	int getpressed_item();
	void  draw(sf::RenderWindow &window);
private:

	int selected_item;
	sf::Font font;
	sf::Text set_text[retry_element];

};
void load_quit();




