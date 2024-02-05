#include <iostream>

class Triangle
{

private:

    int m_a;
    int m_b;
    int m_c;

public:

    Triangle(int a, int b, int c)
    {
        m_a = a;
        m_b = b;
        m_c = c;
    }

    int S(int a, int b, int c)
    {
        int p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    ~Triangle() {}
};

int main()
{
    int a = 3;
    int b = 4;
    int c = 5;

    Triangle triangle(a, b, c);

    std::cout << triangle.S(a, b, c) << std::endl;
}