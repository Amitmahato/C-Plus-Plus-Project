#include <SFML/Graphics.hpp>
#include<iostream>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>
#include"players.h"
#include<vector>
#include"arrow.h"
#include"BackGround.h"
#include"collision.h"
#include"bubble.h"
#include"retry.h"

//#include"logo.h"
#include"BackGround.h"
//#include"ChildBubble.h"

int game_play()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!");
	window.setFramerateLimit(60);

	std::cout << window.getSize().x <<std:: endl;
	std::cout << window.getSize().y <<std:: endl;


	
	players player;
	
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("pop.wav"))
		std::cout << "couldnt load the sound" << std::endl;
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(30);
	player.setpos(window.getSize().x / 2, window.getSize().y - 145);
	Bullet *bullet = new Bullet;
	std::vector<bubbles *>barray;

	BackGround bg;
	
	bg.animate_health();
	sf::Music music;
	if (!music.openFromFile("DarkKnight.ogg"))
		std::cout << "music load error";
	music.setVolume(2);
	music.setLoop(true);
	music.play();
	int draw_variable = 1;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				load_quit();
			}
		}
		window.clear();
		bg.draw(window);
		//

		//player.update();
		//bullet->update(player.getpos().x, player.getpos().y + 50, window);
		if (barray.size() < 4)
		{
			bubbles *b = new bubbles();
			barray.push_back(b);
		}
			player.update();
			bullet->update(player.getpos().x, player.getpos().y + 50, window);

			for (auto i = barray.begin(); i != barray.end();)
			{
				bubbles *b = *i;
				if (b->count < 4)
				{
					b->update(player.returnsprite(), b->bubblesprite(), window);
					b->draw(window);
					i++;
				}
				else
				{
					i = barray.erase(i);
					delete b;
				}
			}
			for (auto b : barray)
			{

				if (Collision::PixelPerfectTest(bullet->returnsprite(), b->bubblesprite()))
				{
					sound.play();
					sf::Vector2f temppos = sf::Vector2f(b->getpos().x, b->getpos().y);

					b->setscale(0.6f / (b->count + 2), 0.6f / (b->count + 2));
					b->setpos(temppos.x, temppos.y);
					b->update(player.returnsprite(), b->bubblesprite(), window);
					b->draw(window);
					(b->count)++;
					
				}
				if (Collision::PixelPerfectTest(player.returnsprite(), b->bubblesprite()))
				{

					std::cout << "you are dead" << std::endl;
					draw_variable=bg.animate_health();


				}

			}
         		

			if (!draw_variable == 0)
				player.draw(window);
			else
			{
				
				load_retry();
				draw_variable = 1;
				bg.animate_health();

			}
				

			     
		window.display();
	}

	return 0;
}