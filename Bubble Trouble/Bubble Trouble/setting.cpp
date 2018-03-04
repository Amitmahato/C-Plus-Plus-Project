#include"setting.h"
#include<iostream>

Settings::Settings(float width, float height)
{
	if (!font.loadFromFile("Trajan Pro Bold.ttf"))
		std::cout << "load error";
	selected_item = 0;
	set_text[0].setFont(font);
	set_text[0].setCharacterSize(30);
	set_text[0].setOutlineThickness(5);
	set_text[0].setFillColor(sf::Color::Red);
	set_text[0].setString("AUDIO");
	set_text[0].setPosition(sf::Vector2f(0.45*width, 0.2*height));


	set_text[1].setFont(font);
	set_text[1].setCharacterSize(30);
	set_text[1].setOutlineThickness(5);
	set_text[1].setFillColor(sf::Color::White);
	set_text[1].setString("CONTROLLER");
	set_text[1].setPosition(sf::Vector2f(0.4*width, 3 * 0.2*height));


}
int Settings::getpressed_item()
{
	return selected_item;
}

void load_settings()
{
	sf::Texture texture;
	if (!texture.loadFromFile("transparent.jpg"))
		std::cout << "error";
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 400));
	sf::RenderWindow window(sf::VideoMode(800, 400), "settings", sf::Style::Default);

	Settings settin(window.getSize().x, window.getSize().y);

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
				case(sf::Keyboard::Up):
				{
					settin.moveup();
					break;
				}
				case(sf::Keyboard::Down):
				{
					settin.movedown();
					break;
				}
				case(sf::Keyboard::Escape):
				{
					window.close();
					break;
				}
				case(sf::Keyboard::Return):
				{
					switch (settin.getpressed_item())
					{
					case 0:
						std::cout << "audio entered";

						break;
					case 1:
						std::cout << "controller entered";
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
		settin.draw(window);
		window.display();

	}
}
void Settings::moveup()
{
	if (selected_item - 1 >= 0)
	{
		set_text[selected_item].setFillColor(sf::Color::White);
		selected_item--;
		set_text[selected_item].setFillColor(sf::Color::Red);
	}

}
void Settings::movedown()
{
	if (selected_item + 1<setting_element)
	{
		set_text[selected_item].setFillColor(sf::Color::White);
		selected_item++;
		set_text[selected_item].setFillColor(sf::Color::Red);

	}
}
void Settings::draw(sf::RenderWindow &window)
{
	for (int i = 0; i<setting_element; i++)
		window.draw(set_text[i]);
}
