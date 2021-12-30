#include "pch.h"
#include "ListOfSchedules.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>

const char* StrFromFile(const char* fileName)
{
	FILE* ptrFile;
	ptrFile = fopen(fileName, "r+"); 
	fseek(ptrFile, 0, SEEK_END);
	long fileSize = ftell(ptrFile);
	rewind(ptrFile);
	char* buffer = new char[fileSize + 1]{};
	fread(buffer, 1, fileSize, ptrFile);
	fclose(ptrFile);
	return buffer;
}
int StrLength(const char* str)
{
	const char* begin = str;
	while (*str++);
	return (int)(str - 1 - begin);
}
int CountOfSructs(const wchar_t* str)
{
	int count = 0;
	while (*str)
	{
		if (*str == L'{')
			++count;
		++str;
	}
	str = str - count;
	return count;
}
const wchar_t* StrToWideStr(const char* str)
{
	int length = StrLength(str);
	int converted = 0;
	wchar_t* wstr = new wchar_t[length + 1];
	converted = mbstowcs(wstr, str, length + 1);
	if (converted != length)
		return nullptr;
	return wstr;
}
const wchar_t* SkipUnnecessarySymbols(const wchar_t* wstr)
{
	int indexOfColon = 0;
	swscanf(wstr, L"%*[^:]%n", &indexOfColon);
	if (wstr[indexOfColon]== L':')
		++indexOfColon;
	return wstr + indexOfColon;
}
Schedule* ListOfSchedules(const char* fileName, int& count)
{
	const char* noWstr = StrFromFile(fileName);
	const wchar_t* wstr = StrToWideStr(noWstr);
	count = CountOfSructs(wstr);
	Schedule* List = new Schedule[count];
	for (int k = 0; k < count; ++k)
	{
		int distance = 0;
		wstr = SkipUnnecessarySymbols(wstr);
		swscanf(wstr, L"%*[^\"]%n", &distance);
		wstr += distance + 1;
		swscanf(wstr, L"%[^\"]s", &List[k].Name);

		distance = 0;
		wstr = SkipUnnecessarySymbols(wstr);
		swscanf(wstr, L"%*[^\"]%n", &distance);
		wstr += distance + 1;
		swscanf(wstr, L"%[^\"]s", &List[k].Subject);
		wstr = SkipUnnecessarySymbols(wstr);

		int trueorfalsecode;
		bool toDays;
		for (int i = 0; i < 6; ++i)
		{
			distance = 0;
			swscanf(wstr, L"%*[^tf]%n", &distance); // true или false
			wstr += distance;
			swscanf(wstr, L"%*[a-z]%n", &trueorfalsecode);
			if(trueorfalsecode == 4)
				toDays = true;
			if(trueorfalsecode == 5)
				toDays = false;
			List[k].Days[i] = toDays;
			++wstr; 
		}
	}
	return List;
}
void OutputListToFile(const char* fileName, Schedule* List, int size)
{
	FILE* fileToOutput;
	fileToOutput = fopen(fileName, "w+");
	//printf("%s", x ? "true" : "false");
	fprintf(fileToOutput, "+------------------------------------------------------------------------------------------------------------------------+\n");
	fprintf(fileToOutput, "|  №  |                       Фамилия                       |          Предмет         |            Даты занятий         |\n");
	fprintf(fileToOutput, "+------------------------------------------------------------------------------------------------------------------------+\n");
	bool day = true;
	for (int i = 0; i < size; ++i)
	{
		fwprintf(fileToOutput, L"|  %-3d|                       %-30s|          %-16s|     %-4s%-4s%-4s%-4s%-4s%-4s    |\n", i + 1, List[i].Name, List[i].Subject, List[i].Days[0]? L"Mon " : L"", List[i].Days[1] ? L"Tue " : L"", List[i].Days[2] ? L"Wed " : L"", List[i].Days[3] ? L"Thu " : L"", List[i].Days[4] ? L"Fri " : L"", List[i].Days[5] ? L"Sat " : L"");
	fprintf(fileToOutput, "+------------------------------------------------------------------------------------------------------------------------+\n");
	}
}
void Sorting(Schedule* List, int size)
{
	int k = 0;
	for(int i =0; i< size-1;i++)
		for (int j = i; j < size;j++)
		{
			if (List[i].Subject[0] <= List[j].Subject[0])
				continue;
			k = 0;
			while (List[i].Subject[k] != '\0' || List[j].Subject[k] != '\0')
			{
				if (List[i].Subject[k] > List[j].Subject[k])
				{
					std::swap(List[i], List[j]);
					break;
				}
				k++;
			}
		}
}
Schedule* Searching(Schedule* List, int& size, const bool* days)
{
	int right = 0;
	for (int i = 0; i < size; i++)
	{
		if (List[i].Days[0] == days[0]&& List[i].Days[1] == days[1] && List[i].Days[2] == days[2] && List[i].Days[3] == days[3] && List[i].Days[4] == days[4] && List[i].Days[5] == days[5])
			right++;
	}
	Schedule* rightNames = new Schedule[right];
	right = 0;
	for (int i = 0; i < size; i++)
	{
		if (List[i].Days[0] == days[0] && List[i].Days[1] == days[1] && List[i].Days[2] == days[2] && List[i].Days[3] == days[3] && List[i].Days[4] == days[4] && List[i].Days[5] == days[5])
		{
			rightNames[right] = List[i];
			right++;
		}
	}
	size = right;
	if (right == 0)
		return nullptr;
	return rightNames;
}
