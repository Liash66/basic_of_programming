#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class AnimatedText
{
private:
	string m_text;
	double m_duration;

public:
	AnimatedText(string text, double duration)
	{
		m_text = text;
		m_duration = duration;
	}

	~AnimatedText()
	{}

	string GetCurrentText(double current_time) {
		string current_text;
		double t0 = m_duration / m_text.size();
		int k = int(current_time) / int(t0);
		for (size_t i = 0; i < k; i++)
		{
			if (i > m_text.size())
				break;
			current_text += m_text[i];
		}
		return current_text;
	}
};

class Window
{
private:
	sf::RenderWindow* m_window = nullptr;
	sf::Clock m_timer;

public:
	Window(const int width, const int height, const string caption)
	{
		m_window = new sf::RenderWindow(sf::VideoMode(width, height), caption);
	}

	~Window()
	{
		if (m_window != nullptr)
			delete m_window;
	}

	void Run()
	{
		AnimatedText animation = AnimatedText("Hello world", 13);

		m_timer.restart();

		sf::Font font;
		if (!font.loadFromFile("assets/Blackletter.ttf"))
			cout << "Can't load font";

		while (m_window->isOpen())
		{
			sf::Event event;
			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window->close();
			}

			m_window->clear();

			sf::Time time = m_timer.getElapsedTime();
			
			sf::Text text;
			text.setString(animation.GetCurrentText(double(time.asSeconds())));
			text.setFont(font);
			text.setFillColor(sf::Color::Green);
			text.setPosition(0, 0);

			m_window->draw(text);

			m_window->display();
		}
	}
};

int main()
{
	Window window(800, 600, "Animated Text");

	window.Run();

	return 0;
}