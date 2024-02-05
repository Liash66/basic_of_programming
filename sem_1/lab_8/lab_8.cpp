#include <iostream>
using namespace std;

int main()
{
    unsigned long long value = INT_MAX;
	unsigned long long* ptr = &value;
	unsigned char* charPtr = (unsigned char*)ptr;
	for (int i = 0; i < 8; i++)
	{
		cout << (int)*charPtr << endl;
		charPtr++;
	}
}