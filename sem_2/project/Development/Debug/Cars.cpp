#include "Cars.h"
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace mt
{
	void Car::Setup()
	{
		m_texture->loadFromFile(m_imagepath);

		m_sprite->setSize(sf::Vector2f(90, 175));
		m_sprite->setTexture(m_texture.get());
		m_sprite->setPosition(m_position.x + 185, m_position.y + 160);
		m_sprite->setOrigin(m_position.x / 7.5, m_position.y / 7.5);

		m_position.x += 185;
		m_position.y += 160;
	}

	sf::RectangleShape* Car::Get()
	{
		return m_sprite.get();
	}

	void PlayerCar::Update(float& time)
	{
		switch (m_dir)
		{
		case 0:
			m_dx = 0;
			m_dy = 0;
			break;

		case 1:
			m_dx = -m_velocity;
			m_dy = 0;
			break;

		case 2:
			m_dx = m_velocity;
			m_dy = 0;
			break;

		case 3:
			m_dx = 0;
			m_dy = -m_velocity;
			break;

		case 4:
			m_dx = 0;
			m_dy = m_velocity;
			break;
		}

		m_position.x += m_dx * time;
		m_position.y += m_dy * time;

		m_velocity = 0;
		m_sprite->setPosition(m_position.x, m_position.y);
		MapInteraction();
	}

	void PlayerCar::MapInteraction()
	{
		for (size_t i = m_position.y / 32; i < (m_position.y + m_height) / 32; i++)
		{
			for (size_t j = m_position.x / 32; j < (m_position.x + m_width) / 32; j++)
			{
				if (TitleMap[i][j] == '0')
				{
					if (m_dy > 0)
						m_position.y = i * 32 - m_height;

					if (m_dy < 0)
						m_position.y = i * 32 + 32;

					if (m_dx > 0)
						m_position.x = j * 32 - m_width;

					if (m_dx < 0)
						m_position.x = j * 32 + 32;
				}
			}
		}
	}

	void PlayerCar::Move(float& time)
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))))
		{
			m_sprite->setRotation(-10);
			m_dir = 1;
			m_velocity = 0.075;
		}

		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
		{
			m_sprite->setRotation(10);
			m_dir = 2;
			m_velocity = 0.075;
		}

		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
		{
			m_sprite->setRotation(0);
			m_dir = 3;
			m_velocity = 0.075;
		}

		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
		{
			m_sprite->setRotation(0);
			m_dir = 4;
			m_velocity = 0.075;
		}

		else
		{
			m_sprite->setRotation(0);
			m_dir = 0;
		}

		Update(time);
	}

	void CivilCar::Setup()
	{
		m_texture->loadFromFile(m_imagepath);

		m_sprite->setSize(sf::Vector2f(90, 175));
		m_sprite->setTexture(m_texture.get());
		m_sprite->setPosition(m_position.x, m_position.y);
	}

	void CivilCar::MapInteraction()
	{
		for (size_t i = m_position.y / 32; i < (m_position.y + m_height) / 32; i++)
		{
			for (size_t j = m_position.x / 32; j < (m_position.x + m_width) / 32; j++)
			{
				if (TitleMap[i][j] == 's')
				{
					srand(time(0));
					double random_number = 1 + rand() % 4;
					int temp = static_cast<int>(random_number);

					if (temp == 1)
					{
						m_position.x = 180;
						m_position.y = -660;
					}

					if (temp == 2)
					{
						m_position.x = 300;
						m_position.y = -660;
					}

					if (temp == 3)
					{
						m_position.x = 440;
						m_position.y = -1200;
					}

					if (temp == 4)
					{
						m_position.x = 560;
						m_position.y = -1200;
					}
				}
			}
		}
	}

	void CivilCar::Move(float& time)
	{
		m_position.y += m_velocity * time;
		m_sprite->setPosition(m_position.x, m_position.y);

		MapInteraction();
	}
}