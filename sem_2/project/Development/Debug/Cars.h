#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
	struct Position
	{
		float x;
		float y;
	};

	class Car
	{
	protected:
		double m_height, m_width, m_velocity;;
		Position m_position;
		std::unique_ptr<sf::RectangleShape> m_sprite = std::make_unique<sf::RectangleShape>();
		std::unique_ptr<sf::Texture> m_texture = std::make_unique<sf::Texture>();
		std::string m_imagepath;

	public:
		sf::String TitleMap[20] = {
			"                     ",
			"      000000000000000",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      0             0",
			"      000000000000000",
			"                     ",
			"                     ",
			"                     ",
			"sssssssssssssssssssss",
		};

		Car(const double& height, const double& width, const double& velocity, const Position& position, const std::string& imagepath) :
			m_height(height), m_width(width), m_velocity(velocity), m_position(position), m_imagepath(imagepath)
		{}

		~Car()
		{}

		virtual void MapInteraction()
		{}

		virtual void Move(float& time)
		{}

		virtual void Setup();

		virtual sf::RectangleShape* Get();
	};

	class PlayerCar : public Car
	{
	private:
		double m_dx, m_dy;
		int m_dir;

	public:
		PlayerCar(const double& m_height, const double& m_width, const Position& m_position, const std::string& m_imagepath) : 
			m_dx(0), m_dy(0), m_dir(0), Car(m_height, m_width, 0, m_position, m_imagepath)
		{}

		~PlayerCar()
		{}

		void MapInteraction() override;

		void Update(float& time);

		void Move(float& time) override;
	};

	class CivilCar : public Car
	{
	public:
		CivilCar(const double& m_height, const double& m_width, const double& m_velocity, const Position& m_position, const std::string& m_imagepath) :
			Car(m_height, m_width, m_velocity, m_position, m_imagepath)
		{}

		~CivilCar()
		{}

		void Setup() override;

		void MapInteraction() override;

		void Move(float& time) override;
	};
}