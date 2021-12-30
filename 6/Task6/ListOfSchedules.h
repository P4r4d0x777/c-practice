#pragma once
#include "Task6Api.hpp"
#include "Schedule.hpp"
TASK6_API const char* StrFromFile(const char* fileName);
TASK6_API int StrLength(const char* str);
TASK6_API int CountOfSructs(const wchar_t* str);
TASK6_API const wchar_t* StrToWideStr(const char* str);
TASK6_API const wchar_t* SkipUnnecessarySymbols(const wchar_t* wstr);
TASK6_API Schedule* ListOfSchedules(const char* str, int& count);
TASK6_API void OutputListToFile(const char* fileName, Schedule* List, int size);
TASK6_API void Sorting(Schedule* List, int size);
TASK6_API Schedule* Searching(Schedule* List, int &size,const bool* days);