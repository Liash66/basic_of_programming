#pragma once
#include <SFML/Graphics.hpp>
#include "Cars.h"

namespace mt
{
	class Game
	{
	private:
		unsigned int m_width, m_height;
		std::string m_caption;
		sf::RenderWindow* m_window = nullptr;
		sf::Clock m_timer;

	public:
		Game()
		{}

		~Game();

		void SetCaption(const std::string& caption);

		void SetResolution(const unsigned int& width, const unsigned int& height);

		void Setup();

		void Run();
	};
}