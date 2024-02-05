#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream file("input.txt", ios::in);
	ofstream out("output.txt", std::ios::out);
	string str;
	string strCheck;

	int k[33] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				  0, 0, 0, 0, 0, 0, 0 };

	int max[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	char kC[33] = { 'ё', 'й', 'ц', 'у', 'к', 'е', 'н', 'г', 'ш',
					'щ', 'з', 'х', 'ъ', 'ф', 'ы', 'в', 'а', 'п',
					'р', 'о', 'л', 'д', 'ж', 'э', 'я', 'ч', 'с',
					'м', 'и', 'т', 'ь', 'б', 'ю' };
	char maxC[8];

	while (!file.eof())
	{
		file >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if ((str[i] == 'ё') or (str[i] == 'Ё'))
				k[0] += 1;
			if ((str[i] == 'й') or (str[i] == 'Й'))
				k[1] += 1;
			if ((str[i] == 'ц') or (str[i] == 'Ц'))
				k[2] += 1;
			if ((str[i] == 'у') or (str[i] == 'У'))
				k[3] += 1;
			if ((str[i] == 'к') or (str[i] == 'К'))
				k[4] += 1;
			if ((str[i] == 'е') or (str[i] == 'Е'))
				k[5] += 1;
			if ((str[i] == 'н') or (str[i] == 'Н'))
				k[6] += 1;
			if ((str[i] == 'г') or (str[i] == 'Г'))
				k[7] += 1;
			if ((str[i] == 'ш') or (str[i] == 'Ш'))
				k[8] += 1;
			if ((str[i] == 'щ') or (str[i] == 'Щ'))
				k[9] += 1;
			if ((str[i] == 'з') or (str[i] == 'З'))
				k[10] += 1;
			if ((str[i] == 'х') or (str[i] == 'Х'))
				k[11] += 1;
			if ((str[i] == 'ъ') or (str[i] == 'Ъ'))
				k[12] += 1;
			if ((str[i] == 'ф') or (str[i] == 'Ф'))
				k[13] += 1;
			if ((str[i] == 'ы') or (str[i] == 'Ы'))
				k[14] += 1;
			if ((str[i] == 'в') or (str[i] == 'В'))
				k[15] += 1;
			if ((str[i] == 'а') or (str[i] == 'А'))
				k[16] += 1;
			if ((str[i] == 'п') or (str[i] == 'П'))
				k[17] += 1;
			if ((str[i] == 'р') or (str[i] == 'Р'))
				k[18] += 1;
			if ((str[i] == 'о') or (str[i] == 'О'))
				k[19] += 1;
			if ((str[i] == 'л') or (str[i] == 'Л'))
				k[20] += 1;
			if ((str[i] == 'д') or (str[i] == 'Д'))
				k[21] += 1;
			if ((str[i] == 'ж') or (str[i] == 'Ж'))
				k[22] += 1;
			if ((str[i] == 'э') or (str[i] == 'Э'))
				k[23] += 1;
			if ((str[i] == 'я') or (str[i] == 'Я'))
				k[24] += 1;
			if ((str[i] == 'ч') or (str[i] == 'Ч'))
				k[25] += 1;
			if ((str[i] == 'с') or (str[i] == 'С'))
				k[26] += 1;
			if ((str[i] == 'м') or (str[i] == 'М'))
				k[27] += 1;
			if ((str[i] == 'и') or (str[i] == 'И'))
				k[28] += 1;
			if ((str[i] == 'т') or (str[i] == 'Т'))
				k[29] += 1;
			if ((str[i] == 'ь') or (str[i] == 'Ь'))
				k[30] += 1;
			if ((str[i] == 'б') or (str[i] == 'Б'))
				k[31] += 1;
			if ((str[i] == 'ю') or (str[i] == 'Ю'))
				k[32] += 1;
		}
	}
	for (int i = 0; i < 32; i++)
		for (int j = i + 1; j < 33; j++)
		{
			if (k[i] < k[j])
			{
				swap(k[i], k[i + 1]);
				swap(kC[i], kC[i + 1]);
			}
		}
	for (int i = 0; i < 8; i++)
	{
		max[i] = k[i];
		maxC[i] = kC[i];
	}
	ifstream fileCheck("input.txt", ios::in);
	while (!fileCheck.eof())
	{
		fileCheck >> strCheck;
		int s = 0;
		vector<char> r;
		for (int i = 0; i < strCheck.length(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((strCheck[i] == maxC[j]) or (strCheck[i] == toupper(maxC[j])))
				{
					s += 1;
					break;
				}
			}
			if (s > 4)
				break;
		}
		if (s > 4)
		{
			for (int i = 0; i < strCheck.length(); i++)
			{
				bool flag = false;
				for (int j = 0; j < 8; j++)
				{
					if ((strCheck[i] == maxC[j]) or (strCheck[i] == toupper(maxC[j])))
					{
						r.push_back(toupper(maxC[j]));
						out << char(toupper(strCheck[i]));
						flag = true;
						break;
					}
				}
				if (flag == false)
					out << char(tolower(strCheck[i]));
			}
			out << ' ' << '(' << ' ';
			for (int i = 0; i < r.size(); i++)
				out << r[i] << ' ';
			out << ')' << endl;
		}
		else
		{
			for (int i = 0; i < strCheck.length() + 1; i++)
			{
				out << strCheck[i];
			}
		}
	}
}