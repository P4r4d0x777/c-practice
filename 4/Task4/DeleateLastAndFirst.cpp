#include "pch.h"
#include "DeleateLastAndFirst.h"
#include<string>
// Количество всех символов - это "длина" в народе называется. Length по-английски
int Length(char* str)
{
	int k = 0;
	while (*str)
	{
		k++;
		++str;
	}
	return k;
}
// во всех вспомогательных функциях вернуть void. Так будет понятно, что вы редактируете исходную строку
void DeleteLast(char* str, const char delim)
{
	int k = Length(str);
	while (str[k] != delim)
	{
		str[k] = '\0';
		k--;
	}
}
void Skiplast(char* str)
{
	int k = Length(str) - 1;
	while (str[k] == ' ')
	{
		str[k] = '\0';
		k--;
	}
}
void Reverse(char* str)
{
	int strlen = Length(str);
	int iterations = strlen / 2;
	int j = 0;
	char ch;
	for (int i = 0; i < iterations; i++)
	{
		ch = str[j];
		str[j] = str[strlen - j-1];
		str[strlen - j-1] = ch;
		j++;
	}
}
// да и тут void вернуть
void DeleateLastAndFirst(char* str)
{
	const char delim = ' ';
	Skiplast(str);
	DeleteLast(str, delim);
	Reverse(str);
	Skiplast(str);
	DeleteLast(str, delim);
	Reverse(str);
}