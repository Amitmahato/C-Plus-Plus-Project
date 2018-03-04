#include"menu.h"
#include"setting.h"
#include"exit.h"
#include"game.h"
#include<iostream>
#include<SFML\Audio.hpp>


Menu::Menu(float width, float height)
{

	selected_item = 0;

	/* sf::Music music;

	if(!music.openFromFile("DarkKnight.ogg"))
	std::cout<<"ogg load error";
	music.play();
	*/
	
	if (!font.loadFromFile("Trajan Pro Bold.ttf"))
		std::cout << "load error";


	menu[0].setFont(font);
	menu[0].setCharacterSize(40);
	menu[0].setOutlineThickness(5);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("PLAY");
	menu[0].setPosition(sf::Vector2f(0.45*width, height / 2.0));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setOutlineThickness(5);
	menu[1].setString("HOW TO PLAY");
	menu[1].setPosition(sf::Vector2f((width / 9.0) * 1, 0.75*height));

	menu[2].setFont(font);
	menu[2].setOutlineThickness(5);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("CREDITS");
	menu[2].setPosition(sf::Vector2f((width / 9.0) * 3 + 50, 0.75*height));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setOutlineThickness(5);
	menu[3].setString("SETTINGS");
	menu[3].setPosition(sf::Vector2f((width / 9.0) * 5, 0.75*height));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setOutlineThickness(5);
	menu[4].setString("EXIT");
	menu[4].setPosition(sf::Vector2f((width / 9.0) * 7, 0.75*height));



	menu[5].setFont(font);
	menu[5].setCharacterSize(70);
	menu[5].setOutlineThickness(8);
	menu[5].setFillColor(sf::Color::Green);
	menu[5].setString("BUBBLE  Trouble");
	menu[5].setPosition(sf::Vector2f(0.22*width, 0.2*height));

}
int Menu::getpressed_item()
{
	return selected_item;
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i<menu_elements; i++)
		window.draw(menu[i]);
}

void Menu::moveup()
{
	if (selected_item - 1 >= 0)
	{
		menu[selected_item].setFillColor(sf::Color::White);
		selected_item--;
		menu[selected_item].setFillColor(sf::Color::Red);
	}

}
void Menu::movedown()
{
	if (selected_item + 1<menu_elements)
	{
		menu[selected_item].setFillColor(sf::Color::White);
		selected_item++;
		menu[selected_item].setFillColor(sf::Color::Red);

	}

}
void Menu::load_menu(sf::RenderWindow &window)
{


	sf::Texture texture;
	if (!texture.loadFromFile("split.jpg"))
		std::cout << "image load error";
	sf::Sprite sprite;
	sprite.setTexture(texture);
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
					moveup();
					break;
				}
				case(sf::Keyboard::Right):
				{
					movedown();
					break;
				}
				case(sf::Keyboard::Escape):
				{
					window.close();
					break;
				}
				case(sf::Keyboard::Return):
				{
					switch (getpressed_item())
					{
					case 0:
						std::cout << "play" << std::endl;
						window.close();
						game_play();
						break;
					case 1:
						std::cout << "how to play" << std::endl;
						break;


					case 2:
						std::cout << "credits" << std::endl;
						break;


					case 3:
						std::cout << "settings " << std::endl;
						load_settings();
						break;
					case 4:
						std::cout << "exit" << std::endl;
						load_quit();
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
		window.clear(sf::Color::White);
		window.draw(sprite);
		draw(window);

		window.display();

	}
}
