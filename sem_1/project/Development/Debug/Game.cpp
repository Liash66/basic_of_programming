#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "Game.h"
#include "Planet.h"

namespace mt
{
	Game::~Game()
	{
		if (m_window != nullptr)
			delete m_window;
	}

	void Game::SetCaption(const std::string caption)
	{
		m_caption = caption;
	}

	void Game::SetResolution(int width, int height)
	{
		m_width = width;
		m_height = height;
	}

	void Game::Setup()
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
	}

	void Game::Run()
	{
		std::vector<mt::Planet*> planets;
		planets.emplace_back(new mt::Planet({ 400, 300, 0 }, 200, "assets/star.png"));
		planets.emplace_back(new mt::Planet({ 0, 0, 200 }, 20, "assets/planet_1.png"));
		planets.emplace_back(new mt::Planet({ 0, 0, 300 }, 35, "assets/planet_2.png"));

		sf::Texture texture;
		if (!texture.loadFromFile("assets/background.jpg"))
			std::cout << "Can't load background";
		sf::Sprite background;
		background.setTexture(texture);
		background.setScale(0.33, 0.33);

		for (int i = 0; i < planets.size(); i++)
			planets[i]->Setup();

		m_timer.restart();
		double t = 0;

		while (m_window->isOpen())
		{
			sf::Event event;
			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window->close();
			}

			sf::Time dt = m_timer.restart();
			t += dt.asSeconds();

			planets[1]->Move(t / 2);
			planets[2]->Move(t / 3);

			m_window->clear();
			m_window->draw(background);
			for (int i = 0; i < planets.size(); i++)
				m_window->draw(*planets[i]->Get());
			m_window->display();

			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}

		for (int i = 0; i < planets.size(); i++)
			delete planets[i];
	}
}