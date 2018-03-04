#include <iostream>
#include<SFML/Graphics.hpp>
#include"menu.h"


using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Bubble Troublr", sf::Style::Default);
	Menu m(window.getSize().x, window.getSize().y);
	m.load_menu(window);
	return 0;
}

