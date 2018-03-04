#pragma once
#include<SFML/Graphics.hpp>
#define setting_element 2

class Settings
{
public:
	Settings(float width, float height);
	void load_settings();
	void moveup();
	void movedown();
	int getpressed_item();
	void  draw(sf::RenderWindow &window);
private:

	int selected_item;
	sf::Font font;
	sf::Text set_text[setting_element];

};
void load_settings();

#pragma once
#pragma once
