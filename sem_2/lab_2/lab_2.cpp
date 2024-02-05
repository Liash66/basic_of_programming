#include <iostream>

class String
{
private:
    size_t m_size;
    char* m_str;

public:
    String() : m_size(0), m_str(nullptr)
    {};

    String(char c, size_t size) : m_size(size), m_str(new char[size])
    {
        std::fill(m_str, m_str + m_size, c);
    }

    String(const char* str) : m_size(strlen(str)), m_str(new char[m_size])
    {
        std::copy(str, str + m_size, m_str);
    }

    String(const String& other) : String(other.m_str)
    {
        m_size = other.m_size;
        m_str = new char[m_size];
        std::copy(other.m_str, other.m_str + other.m_size, m_str);
    }

    ~String()
    {
        if (m_str != nullptr)
            delete[] m_str;
    }

    String operator + (const String c)
    {
        size_t newSize = c.length();

        char* newStr = new char[m_size + newSize + 1];

        for (size_t i = 0; i < m_size; i++)
        {
            newStr[i] = m_str[i];
        }

        for (size_t i = 0; i < newSize; i++)
        {
            newStr[m_size + i] = c.m_str[i];
        }

        delete m_str;

        m_str = newStr;

        m_size += newSize;

        newStr[m_size] = '\0';

        return m_str;
    }

    String operator += (const String c)
    {
        size_t newSize = c.length();

        char* newStr = new char[m_size + newSize + 1];

        for (size_t i = 0; i < m_size; i++)
        {
            newStr[i] = m_str[i];
        }

        for (size_t i = 0; i < newSize; i++)
        {
            newStr[m_size + i] = c.m_str[i];
        }

        delete m_str;

        m_str = newStr;

        m_size += newSize;

        newStr[m_size] = '\0';

        return m_str;
    }

    char operator [] (const size_t i)
    {
        return m_str[i];
    }

    bool operator > (const char* s)
    {
        bool temp = false;
        if (m_str > s)
            temp = true;
        return temp;
    }

    bool operator < (const char* s)
    {
        bool temp = false;
        if (m_str < s)
            temp = true;
        return temp;
    }

    bool operator == (const char* s)
    {
        bool temp = false;
        if (m_str == s)
            temp = true;
        return temp;
    }

    int find(char c)
    {
        for (int i = 0; i < m_size; i++)
            if (m_str[i] == c)
            {
                return i;
            }
    }

    size_t length() const
    {
        return m_size;
    }

    char* c_str()
    {
        char* new_mas = new char[m_size];
        for (int i = 0; i < m_size; i++)
            new_mas[i] = m_str[i];
        return new_mas;
    }

    char at(size_t i)
    {
        if (i < m_size)
            return m_str[i];
        else
            std::cout << "ERROR: out of range";
    }

    friend std::ostream& operator << (std::ostream& out, String& s);
    friend std::istream& operator >> (std::istream& in, String& s);
};

std::istream& operator >> (std::istream& in, String& s)
{
    size_t newSize = 0;

    char c[100] = { '\0' };

    in.getline(c, 100);

    for (size_t i = 0; i < 100; i++) {
        if (c[i] != '\0') {
            newSize++;
        }
    }

    char* newStr = new char[s.m_size + newSize];

    for (size_t i = 0; i < s.m_size; i++)
    {
        newStr[i] = s.m_str[i];
    }

    for (size_t i = 0; i < newSize; i++)
    {
        newStr[s.m_size + i] = c[i];
    }

    delete s.m_str;

    s.m_str = newStr;

    s.m_size = s.m_size + newSize;

    return in;
}

std::ostream& operator << (std::ostream& out, String& s)
{
    char* c = s.c_str();
    for (size_t i = 0; i < s.m_size; i++) {
        out << c[i];
    }

    return out;
}

int main()
{
    String s;
    std::cin >> s;
    std::cout << s;
    return 0;
}