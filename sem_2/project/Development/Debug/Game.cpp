#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Cars.h"
#include "Map.h"
#include "Logger.h"
#include <vector>
#include <iostream>

namespace mt
{
	Game::~Game()
	{
		if (m_window != nullptr)
			delete m_window;
	}

	void Game::SetCaption(const std::string& caption)
	{
		m_caption = caption;
	}

	void Game::SetResolution(const unsigned int& width, const unsigned int& height)
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
		utils::Log::SetLogPath("log.txt");

		float time = m_timer.getElapsedTime().asMilliseconds();
		m_timer.restart();
		time = time / 8;

		bool flag = true;
		int k = 0;

		sf::Font font;
		font.loadFromFile("images/fonts/UrbanJungleDEMO.otf");
		sf::Text text("", font, 20);
		text.setFillColor(sf::Color::Red);
		text.setCharacterSize(20);

		std::vector<mt::Map*> Maps;
		try
		{
			Maps.emplace_back(new mt::Map(850, { 0, 0 }, "images/background/background-1.png"));
			Maps.emplace_back(new mt::Map(850, { 0, -630 }, "images/background/background-1.png"));
		}
		catch (const std::overflow_error& error)
		{
			utils::Log::Write(utils::LogLevel::ERROR, error.what());
		}
		
		utils::Log::Write(utils::LogLevel::INFO, "Map created");

		for (size_t i = 0; i < Maps.size(); i++)
		{
			Maps[i]->Setup();
		}

		utils::Log::Write(utils::LogLevel::INFO, "Map loaded");

		std::vector<mt::Car*> PlayerCars;
		try
		{
			PlayerCars.emplace_back(new mt::PlayerCar(10, 10, { 440, 200 }, "images/cars/audi.png"));
		}
		catch (const std::overflow_error& error)
		{
			utils::Log::Write(utils::LogLevel::ERROR, error.what());
		}

		utils::Log::Write(utils::LogLevel::INFO, "Player car created");

		std::vector<mt::Car*> CivilCars;
		try
		{
			CivilCars.emplace_back(new mt::CivilCar(10, 2, 0.03, { 180, -660 }, "images/cars/taxi.png"));
			CivilCars.emplace_back(new mt::CivilCar(10, 2, 0.026, { 300, -1400 }, "images/cars/Mini_truck.png"));
			CivilCars.emplace_back(new mt::CivilCar(10, 2, 0.028, { 440, -2000 }, "images/cars/Black_viper.png"));
			CivilCars.emplace_back(new mt::CivilCar(10, 2, 0.033, { 560, -2000 }, "images/cars/Car.png"));
		}
		catch (const std::overflow_error& error)
		{
			utils::Log::Write(utils::LogLevel::ERROR, error.what());
		}

		utils::Log::Write(utils::LogLevel::INFO, "Civilian cars created");

		for (size_t i = 0; i < PlayerCars.size(); i++)
		{
			PlayerCars[i]->Setup();
		}

		utils::Log::Write(utils::LogLevel::INFO, "Player car loaded");

		for (size_t i = 0; i < CivilCars.size(); i++)
		{
			CivilCars[i]->Setup();
		}

		utils::Log::Write(utils::LogLevel::INFO, "Civilian cars loaded");

		while (m_window->isOpen())
		{
			sf::Event event;
			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window->close();
			}

			for (size_t i = 0; i < Maps.size(); i++)
			{
				Maps[i]->Move(time);
			}

			for (size_t i = 0; i < PlayerCars.size(); i++)
			{
				PlayerCars[i]->Move(time);
			}

			for (size_t i = 0; i < CivilCars.size(); i++)
			{
				CivilCars[i]->Move(time);
			}

			for (size_t i = 0; i < PlayerCars.size(); i++)
			{
				for (size_t j = 0; j < CivilCars.size(); j++)
				{
					if (PlayerCars[i]->Get()->getGlobalBounds().intersects(CivilCars[j]->Get()->getGlobalBounds()))
					{
						flag = false;
						time = 0;
						if (k == 0)
							utils::Log::Write(utils::LogLevel::INFO, "Player car deleted");
						else
							break;
						k++;
					}
				}
			}

			m_window->clear();
			
			for (size_t i = 0; i < Maps.size(); i++)
			{
				m_window->draw(*Maps[i]->Get());
			}

			if (flag == true)
				for (size_t i = 0; i < PlayerCars.size(); i++)
				{
					m_window->draw(*PlayerCars[i]->Get());
				}

			for (size_t i = 0; i < CivilCars.size(); i++)
			{
				m_window->draw(*CivilCars[i]->Get());
			}

			m_window->display();
		}

		utils::Log::Write(utils::LogLevel::INFO, "Game closed");
	}
}