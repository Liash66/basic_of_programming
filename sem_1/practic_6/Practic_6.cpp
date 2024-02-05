#include <iostream>
#include <vector>
using namespace std;


int main() {
    std::vector<int> vector; // создание массива
    vector.reserve(7); // изменение вместимости массива на '7'
    vector.resize(10); // изменение количества элементов на '10'
    cout << vector.capacity() << endl; // вывод вместимости массива
    vector.push_back(5); //добавление копии '5' в конец массива
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i];
    }
    cout << endl;
    cout << endl;
    vector.emplace_back(3); //создание '3' в конце массива
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i];
    }
    cout << endl;
    cout << endl;
    vector.insert(vector.begin() + 5, 1); //добавление '1' на 6-ую позицию в массиве (все следующие элементы смещаются на 1 вправо)
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i];
    }
    cout << endl;
    cout << endl;
    vector.erase(vector.begin(), vector.begin() + 5); //удаление диапазона от 0 до 5 в массиве
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i];
    }
    cout << endl;
    cout << endl;
    vector.shrink_to_fit(); //изменение вместимости массива под кол-во его элементов
    for (int i = 0; i < vector.size(); i++)
    {
        vector[i] = 9; //присваивание элементу массива по индексу 'i' значения '9'
        cout << vector[i]; //вывод элемента по индексу 'i'
    }
    vector.clear(); // удаление всех элементов в массиве
}