#include <iostream>

class Complex
{
private:
    double m_a;
    double m_b;

public:
    Complex() : m_a(0.0), m_b(0.0)
    {}

    Complex(double a, double b) : m_a(a), m_b(b)
    {}

    Complex(const Complex& other)
    {
        m_a = other.m_a;
        m_b = other.m_b;
    }

    ~Complex()
    {}

    Complex operator = (const Complex x)
    {
        Complex temp = *this;

        temp.m_a = x.m_a;
        temp.m_b = x.m_b;

        return temp;
    }

    Complex operator += (const Complex x)
    {
        Complex temp = *this;

        temp.m_a += x.m_a;
        temp.m_b += x.m_b;

        return temp;
    }

    Complex operator + (const Complex x)
    {
        Complex temp = *this;

        temp.m_a += x.m_a;
        temp.m_b += x.m_b;

        return temp;
    }

    Complex operator *= (const Complex x)
    {
        Complex temp = *this;

        temp.m_a *= x.m_a;
        temp.m_b *= x.m_b;

        return temp;
    }

    Complex operator * (const Complex x)
    {
        Complex temp = *this;

        temp.m_a *= x.m_a;
        temp.m_b *= x.m_b;

        return temp;
    }

    Complex operator ++ ()
    {
        Complex temp = *this;

        temp.m_a *= 1;

        return temp;
    }

    friend std::istream& operator >> (std::istream& in, Complex& z);
    friend std::ostream& operator << (std::ostream& out, Complex& z);
};

std::istream& operator >> (std::istream &in, Complex &z)
{
    in >> z.m_a;
    in >> z.m_b;

    return in;
}

std::ostream& operator << (std::ostream& out, Complex &z)
{
    out << "{ " << z.m_a << " , " << z.m_b << " }";

    return out;
}

int main()
{
    Complex z;

    std::cin >> z;
    std::cout << z;

    return 0;
}