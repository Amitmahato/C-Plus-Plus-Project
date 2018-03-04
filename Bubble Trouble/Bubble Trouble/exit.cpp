#include"exit.h"
#include<iostream>

Quit::Quit(float width, float height)
{
	if (!font.loadFromFile("Trajan Pro Bold.ttf"))
		std::cout << "load error";
	selected_item = 1;
	set_text[0].setFont(font);
	set_text[0].setCharacterSize(30);
	set_text[0].setOutlineThickness(5);
	set_text[0].setFillColor(sf::Color::White);
	set_text[0].setString("Exit Bubble Play ?");
	set_text[0].setPosition(sf::Vector2f(0.35*width, 0.2*height));

	set_text[1].setFont(font);
	set_text[1].setCharacterSize(25);
	set_text[1].setOutlineThickness(5);
	set_text[1].setFillColor(sf::Color::Red);
	set_text[1].setString("Cancel");
	set_text[1].setPosition(sf::Vector2f(0.30*width, 0.6*height));


	set_text[2].setFont(font);
	set_text[2].setCharacterSize(25);
	set_text[2].setOutlineThickness(5);
	set_text[2].setFillColor(sf::Color::White);
	set_text[2].setString("OK");
	set_text[2].setPosition(sf::Vector2f(0.60*width, 0.6*height));
}
int Quit::getpressed_item()
{
	return selected_item;
}

void load_quit()
{
	sf::Texture texture;
	if (!texture.loadFromFile("transparent.jpg"))
		std::cout << "error";
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 400));
	sf::RenderWindow window(sf::VideoMode(800, 300), "exit", sf::Style::Default);

	Quit q(window.getSize().x, window.getSize().y);

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
					q.moveleft();
					break;
				}
				case(sf::Keyboard::Right):
				{
					q.moveright();
					break;
				}
				case(sf::Keyboard::Escape):
				{
					window.close();
					break;
				}
				case(sf::Keyboard::Return):
				{
					switch (q.getpressed_item())
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
		q.draw(window);
		window.display();

	}
}
void Quit::moveleft()
{
	if (selected_item - 1>0)
	{
		set_text[selected_item].setFillColor(sf::Color::White);
		selected_item--;
		set_text[selected_item].setFillColor(sf::Color::Red);
	}

}
void Quit::moveright()
{
	if (selected_item + 1<retry_element)
	{
		set_text[selected_item].setFillColor(sf::Color::White);
		selected_item++;
		set_text[selected_item].setFillColor(sf::Color::Red);

	}
}
void Quit::draw(sf::RenderWindow &window)
{
	for (int i = 0; i<retry_element; i++)
		window.draw(set_text[i]);
}

