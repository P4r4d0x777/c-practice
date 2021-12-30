#include "pch.h"
#include "ArrayOfWords.h"
#include<string>
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
	return (int)(p - str) ;
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
char** ArrayOfWords(const char* str)
{
	if (str == nullptr || *str == '\0')
		return nullptr;
	const char* delim = " ;";
	str = SkipDelimiters(str, delim);
	int count = CountOfWordsInString(str, delim);
	int wordLength = 0;
	int i = 0;
	char** words = new char* [count];
	while (*str)
	{
		wordLength = WordLength(str, delim);
		words[i] = new char[wordLength + 1];
		CopyString(words[i], str, wordLength);
		*(words[i++] + wordLength) = '\0';
		str += wordLength;
		str = SkipDelimiters(str, delim);
	}
	return words;
}				//почему первый параметр - это массив строк? в задании сказано, что в СТРОКЕ найти количство заданных слов
int Count(const char* str1, const char* word)
{
	int count = CountOfWordsInString(str1, " ;");
	// это было заданное слово, перенёс его в параметр функции
	// это не понял, чтол такое abc и почему эта магическая строка тут оказалась?
	std::string perfect2 = word;
	int temp = 0;
	char** arrayOfWords = ArrayOfWords(str1);
	for (int i = 0; i < count; ++i)
	{
		std::string perfect1 = arrayOfWords[i];
		if (perfect1 == perfect2)
		{
			temp++;
		}
	}
	for (int i = 0; i < count; ++i)
		delete[] arrayOfWords[i];
	delete[] arrayOfWords;
	return temp;
}      