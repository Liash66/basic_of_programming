#include "Map.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

namespace mt
{

	void Map::Setup()
	{
		m_texture->loadFromFile(m_imagepath);

		m_sprite->setTexture(*m_texture);
		m_sprite->setPosition(m_position.x, m_position.y);
	}

	void Map::MapCheck()
	{
		for (size_t i = m_position.y / 32; i < (m_position.y + m_height) / 32; i++)
		{
			if (TitleMap[i][0] == 's')				
			{
				m_position.y = -630;
			}
		}
	}

	void Map::Move(float& time)
	{
		m_position.y += 0.4 * time;
		m_sprite->setPosition(m_position.x, m_position.y);

		MapCheck();
	}

	sf::Sprite* Map::Get()
	{
		return m_sprite.get();
	}
}