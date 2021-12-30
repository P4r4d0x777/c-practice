#include "pch.h"
#include "ArrayOfWordsEqual.h"
const char* SkipSpaces(const char* str)
{
	while (*str == ' ')
		++str;
	return str;
}
bool CharBelongsToString(char ch, const char* str)
{
	while (*str)
		if (ch == *str++)
			return true;
	return false;
}
const char* SkipDelimiters(const char* str, const char* delim)
{
	while (*str && CharBelongsToString(*str, delim))
		++str;
	return str;
}
int WordLength(const char* str, const char* delim)
{
	const char* p = str;
	while (*p && !CharBelongsToString(*p, delim))
		++p;
	return (int)(p - str);
}
const char* NextWord(const char* str, const char* delim)
{
	str += WordLength(str, delim);
	str = SkipDelimiters(str, delim);
	return str;
}
int CountOfWordsInString(const char* str, const char* delim)
{
	int count = 0;
	str = SkipDelimiters(str, delim);
	while (*str)
	{
		str = NextWord(str, delim);
		++count;
	}
	return count;
}
bool CopyString(char* dest, const char* source, int count)
{
	if (dest == nullptr || source == nullptr)
		return false;
	for (int i = 0; i < count; ++i)
		*dest++ = *source++;
	return true;
}
// Ќе надо двумерный массив, если таких групп несколько, возвращать всегда первую (или последнюю, как хотите)
char* ArrayOfWordsEqual(const char* str)
{
	const char* delim = " ";
	str = SkipDelimiters(str, delim);
	str = SkipSpaces(str);
	int count = CountOfWordsInString(str, delim);
	int wordLength = 0;
	int lengthOfWord = 0; 
	char* words = nullptr;
	while (*str)
	{
		wordLength = WordLength(str, delim);
		if (WordLength(str, delim) > lengthOfWord)
		{
			delete[] words;
			lengthOfWord = WordLength(str, delim);
			words = new char[wordLength + 1]; // у вас этот word - это другая, новая каждый раз переменная. Вы тесты запускали?
			// Вы в цикле выделяете память каждый раз, но не освобождаете
			// Все равно, в цикле происходит выделение динамической памяти, но вы ее не освобождаете.
			// То есть при каждой итерации у вас значение words будет новым, а старое утрачивается, что приводит
			// к утечке памяти
			CopyString(words, str, wordLength);
			*(words + wordLength) = '\0';
			str += wordLength;
			str = SkipSpaces(str);
		}
		else
		{
			str += wordLength;
			str = SkipSpaces(str);
		}
	}
	return words; // у вас всегда будет возвращаться NULL
}