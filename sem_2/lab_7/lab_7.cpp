#include <iostream>

enum class Color
{
    RED, GREEN, BLUE
};

class Figure
{
protected:
    double m_x;
    double m_y;
    Color m_color;

public:
    Figure(double x, double y, Color color) : m_x(x), m_y(y), m_color(color)
    {};

    virtual double S()
    {
        return 0;
    }

    ~Figure() {}
};

class Triangle : public Figure
{
private:
    double m_a, m_b, m_c, m_S;

public:
    Triangle(double a, double b, double c, double m_x,
        double m_y, Color m_color) : Figure(m_x, m_y, m_color)
    {
        m_a = a;
        m_b = b;
        m_c = c;
        m_S = 0.0;
    }

    double S() override
    {
        double p = (m_a + m_b + m_c) / 2;
        m_S = sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
        return m_S;
    }

    ~Triangle() {}
};

class Rectangle : public Figure
{
protected:
    double m_a, m_b, m_S;

public:
    Rectangle(double a, double b, double m_x, double m_y,
        Color m_color) : Figure(m_x, m_y, m_color)
    {
        m_a = a;
        m_b = b;
        m_S = 0.0;
    }

    double S() override
    {
        m_S = m_a * m_b;
        return m_S;
    }

    ~Rectangle() {}
};

class Circle : public Figure
{
protected:
    double m_r, m_S;

public:
    Circle(double r, double m_x, double m_y, Color m_color) : Figure(m_x, m_y, m_color)
    {
        m_r = r;
        m_S = 0.0;
    }
    
    double S() override
    {
        m_S = m_r * m_r * 3.14;
        return m_S;
    }

    ~Circle() {}
};

int main()
{
    Figure* triangle = new Triangle(3, 4, 5, 0, 0, Color::GREEN);
    Figure* rectangle = new Rectangle(3, 4, 0, 0, Color::RED);
    Figure* circle = new Circle(3, 0, 0, Color::BLUE);

    std::cout << triangle->S() << std::endl;
    std::cout << rectangle->S() << std::endl;
    std::cout << circle->S() << std::endl;

    delete triangle;
    delete rectangle;
    delete circle;

    return 0;
}