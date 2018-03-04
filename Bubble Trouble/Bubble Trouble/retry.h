#pragma once

#include"exit.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#define retry_element 3

class Retry
{
public:
	Retry(float width, float height);
	void load_retry();
	void moveleft();
	void moveright();
	int getpressed_item();
	void  draw(sf::RenderWindow &window);
private:

	int selected_item;
	sf::Font font;
	sf::Text set_text[retry_element];

};
void load_retry();




//cpp part of this file


Retry::Retry(float width, float height)
{
	if (!font.loadFromFile("Trajan Pro Bold.ttf"))
		std::cout << "load error";
	selected_item = 1;
	set_text[0].setFont(font);
	set_text[0].setCharacterSize(30);
	set_text[0].setOutlineThickness(5);
	set_text[0].setFillColor(sf::Color::White);
	set_text[0].setString("Want to retry ?");
	set_text[0].setPosition(sf::Vector2f(0.35*width, 0.2*height));

	set_text[1].setFont(font);
	set_text[1].setCharacterSize(25);
	set_text[1].setOutlineThickness(5);
	set_text[1].setFillColor(sf::Color::Red);
	set_text[1].setString("Yes");
	set_text[1].setPosition(sf::Vector2f(0.30*width, 0.6*height));


	set_text[2].setFont(font);
	set_text[2].setCharacterSize(25);
	set_text[2].setOutlineThickness(5);
	set_text[2].setFillColor(sf::Color::White);
	set_text[2].setString("No");
	set_text[2].setPosition(sf::Vector2f(0.60*width, 0.6*height));
}
int Retry::getpressed_item()
{
	return selected_item;
}

void load_retry()
{
	sf::Texture texture;
	if (!texture.loadFromFile("transparent.jpg"))
		std::cout << "error";
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 400));
	sf::RenderWindow window(sf::VideoMode(800, 300), "retry", sf::Style::Default);

	Retry r(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case(sf::Event::KeyPressed):
			{
				switch (event.key.code)
				{
				case(sf::Keyboard::Left):
				{
					r.moveleft();
					break;
				}
				case(sf::Keyboard::Right):
				{
					r.moveright();
					break;
				}
				case(sf::Keyboard::Escape):
				{
					window.close();
					break;
				}
				case(sf::Keyboard::Return):
				{
					switch (r.getpressed_item())
					{
					case 1:
						window.close();
						break;
					case 2:
						exit(0);
						break;
					}
					break;
				}
				default:
					break;
				}
				break;
			}
			case(sf::Event::Closed):
				window.close();
			default:
				break;
			}
		}
		window.clear(sf::Color::Green);
		window.draw(sprite);
		r.draw(window);
		window.display();

	}
}
void Retry::moveleft()
{
	if (selected_item - 1>0)
	{
		set_text[selected_item].setFillColor(sf::Color::White);
		selected_item--;
		set_text[selected_item].setFillColor(sf::Color::Red);
	}

}
void Retry::moveright()
{
	if (selected_item + 1<retry_element)
	{
		set_text[selected_item].setFillColor(sf::Color::White);
		selected_item++;
		set_text[selected_item].setFillColor(sf::Color::Red);

	}
}
void Retry::draw(sf::RenderWindow &window)
{
	for (int i = 0; i<retry_element; i++)
		window.draw(set_text[i]);
}

