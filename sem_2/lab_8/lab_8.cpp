#include <iostream>

template<typename T>
class Stack
{
private:
    int m_k;
    int m_kmax;
    char* m_mas = nullptr;

public:
    Stack(int size) : m_k(0), m_kmax(size)
    {
        m_mas = new char[size * sizeof(T)];
        if (!m_mas) {
            throw std::runtime_error("Can't get stack memory");
        }
    }

    Stack(const Stack<T>& other)
    {
        m_mas = new char[other.m_kmax * sizeof(T)];
        m_k = other.m_k;
        m_kmax = other.m_kmax;
    }

    ~Stack()
    {
        if (!m_mas)
            delete[] m_mas;
    }

    int size() const
    {
        return m_k;
    }

    bool empty() const
    {
        if (m_k == 0)
        {
            return true;
        }
        return false;
    }

    void push(const T& temp)
    {
        if (m_k < m_kmax)
        {
            m_mas[m_k] = temp;
            m_k++;
        }
        else
        {
            throw std::overflow_error("Невозможно добавить новый элемент в стек");
        }
    }

    T pop()
    {
        if (m_k != 0)
        {
            m_k--;
            return m_mas[m_k];
        }
        throw std::out_of_range("Невозможно извлечь элемент из стека, так как стек пустой");
    }

    T top()
    {
        if (m_k != 0)
        {
            return m_mas[m_k];
        }
        throw std::logic_error("Невозможно посмотреть элемент на вершине стека, так как стек пустой");
    }
};

enum ErrorType {
    STACK_CREATION = 1,
    STACK_ADDING = 2,
    STACK_OUTOFRANGE = 3,
    STACK_EMPTY = 4
};

void choose_error() {
    int choosed_type;
    std::cout << "Choose error type example\n";
    std::cout << "STACK_CREATION = 1\n\
        STACK_ADDING = 2 \n\
        STACK_OUTOFRANGE = 3\n\
        STACK_EMPTY = 4\n";
    std::cout << "Write:\n";
    std::cin >> choosed_type;

    ErrorType type = static_cast<ErrorType>(choosed_type);
    switch (type)
    {
    case STACK_CREATION:
    {
        Stack<int> mas_(1000000000000000000);

        break;
    }

    case STACK_ADDING:
    {
        Stack<int> mas(1);

        mas.push(1);
        mas.push(1);

        break;
    }

    case STACK_OUTOFRANGE:
    {
        Stack<int> mas(1);

        mas.pop();
        mas.pop();

        break;
    }

    case STACK_EMPTY:
    {
        Stack<int> mas(1);

        mas.top();

        break;
    }

    default:
        std::cout << "unknown type\n";
        break;
    }
    Stack<int> mas(1);

    mas.top();
}

int main() {
    setlocale(LC_ALL, "Rus");

    try
    {
        choose_error();
    }
    catch (const std::bad_alloc& err)
    {
        std::cerr << "Невозможно выделить необходимый участок памяти под стек" << std::endl;
    }
    catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (const std::overflow_error& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (const std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (const std::logic_error& err) {
        std::cerr << err.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Ничего..." << std::endl;
    }

    return 0;
}