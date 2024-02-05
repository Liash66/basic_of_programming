#include <iostream>

template<typename T, size_t N, size_t M>
class Matrix
{
private:
    T matrix[N][M];

public:
    Matrix()
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& other)
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    ~Matrix() {}

    Matrix& operator = (const Matrix& other)
    {
        if (this == &other)
        {
            return *this;
        }
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }

        return *this;
    }

    Matrix& operator + (const Matrix& other)
    {
        Matrix temp;
        if (N != M)
        {
            throw "good buy";
        }
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                temp.matrix[i][j] += matrix[i][j] + other.matrix[i][j];
            }
        }

        return temp;
    }

    Matrix& operator += (const Matrix& other) const
    {
        Matrix temp;
        if (N != M)
        {
            throw "good buy";
        }
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                temp.matrix[i][j] += matrix[i][j] + other.matrix[i][j];
            }
        }

        return temp;
    }

    Matrix& operator * (const Matrix& other)
    {
        if (N != M)
        {
            throw "good buy";
        }
        Matrix temp;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                for (size_t k = 0; k < M; k++)
                {
                    temp.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return temp;
    }

    Matrix& operator *= (const Matrix& other)
    {
        if (N != M)
        {
            throw "good buy";
        }
        Matrix temp;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                for (size_t k = 0; k < M; k++)
                {
                    temp.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return temp;
    }

    Matrix& operator ++ ()
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                matrix[i][j] += matrix[i][j] + 1;
            }
        }

        return *this;
    }

    T det() const
    {
        if ((N == 1) && (M == 1))
        {
            return matrix[0][0];
        }
        else if ((N == 2) && (M == 2))
        {
            return matrix[0][0] * matrix[1][1]
                - matrix[0][1] * matrix[1][0];
        }
        else if ((N == 3) && (M == 3))
        {
            return matrix[0][0] * matrix[1][1] * matrix[2][2]
                + matrix[0][1] * matrix[1][2] * matrix[2][0]
                + matrix[0][2] * matrix[1][0] * matrix[2][1]
                - matrix[0][2] * matrix[1][1] * matrix[2][0]
                - matrix[0][1] * matrix[1][0] * matrix[2][2]
                - matrix[0][0] * matrix[1][2] * matrix[2][1];
        }
        else if ((N > 3) || (M > 3))
            throw "ERROR";
    }

    T& at(size_t i, size_t j)
    {
        return matrix[i][j];
    }

    template<typename T, size_t N, size_t M>
    friend std::istream& operator >> (std::istream& in, Matrix<T, N, M>& other);
    template<typename T, size_t N, size_t M>
    friend std::ostream& operator << (std::ostream& out, const Matrix<T, N, M>& other);
};

template<typename T, size_t N, size_t M>
std::istream& operator >> (std::istream& in, Matrix<T, N, M>& other)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            in >> other.matrix[i][j];
        }
    }

    return in;
}

template<typename T, size_t N, size_t M>
std::ostream& operator << (std::ostream& out, const Matrix<T, N, M>& other)
{
    out << std::endl;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            out << other.matrix[i][j] << ' ';
        }
        out << std::endl;
    }

    return out;
}

int main()
{
    Matrix<int, 2, 2> A;
    Matrix<int, 2, 2> B;
    Matrix<int, 2, 2> C;
    Matrix<int, 2, 2> D;

    std::cin >> A;
    std::cin >> B;
    C = A + B;
    D = A * B;
    std::cout << "Сложение" << std::endl << C << std::endl;
    std::cout << "Умножение" << std::endl << D << std::endl;
    std::cout << "Определитель A" << std::endl << A.det() << std::endl;
    std::cout << "A++" << std::endl << (++A) << std::endl;
    std::cout << "Элемент A" << std::endl << A.at(1, 1);

    return 0;
}