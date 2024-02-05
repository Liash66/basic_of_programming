#pragma once

namespace mt
{
	struct Position
	{
		int x;
		int y;
		float R;
	};

	class Planet
	{
	private:
		sf::CircleShape* m_shape;
		Position m_p0;
		float m_r;
		sf::Texture* m_texture = nullptr;
		std::string m_image;

	public:
		Planet(Position p0, float r, std::string image)
		{
			m_image = image;
			m_p0 = p0;
			m_r = r;
			m_shape = new sf::CircleShape(m_r);
			m_shape->setOrigin(m_r-500, m_r-350);
		}

		~Planet()
		{
			delete m_shape;
			if (m_texture != nullptr)
				delete m_texture;
		}

		void Move(double t)
		{
			double x = m_p0.x + m_p0.R * cos(t);
			double y = m_p0.y + m_p0.R * sin(t);
			m_shape->setPosition(x, y);
		}

		void Setup()
		{
			m_texture = new sf::Texture;
			if (!m_texture->loadFromFile(m_image))
				std::cout << "Can't load texture";
			m_shape->setTexture(m_texture);
		}

		sf::CircleShape* Get() { return m_shape; }
	};
}