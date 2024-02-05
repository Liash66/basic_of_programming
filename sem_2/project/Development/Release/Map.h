#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
	struct Coords
	{
		float x;
		float y;
	};

	class Map
	{
	private:
		double m_height;
		Coords m_position;
		std::unique_ptr<sf::Sprite> m_sprite = std::make_unique<sf::Sprite>();
		std::unique_ptr<sf::Texture> m_texture = std::make_unique<sf::Texture>();
		std::string m_imagepath;

	public:
		sf::String TitleMap[88] = {
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			" ",
			"s",
		};

		Map(const double& height, const Coords& position, const std::string& imagepath) :
			m_height(height), m_position(position), m_imagepath(imagepath)
		{}

		~Map()
		{}

		void Setup();

		void MapCheck();

		void Move(float& time);

		sf::Sprite* Get();
	};
}