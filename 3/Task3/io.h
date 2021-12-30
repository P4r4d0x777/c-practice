#pragma once
#include "Task3Api.hpp"
TASK3_API bool InputArrayFromStream(double* arr, size_t count, std::istream& inpStream);
TASK3_API bool InputArrayFromStr(double* arr, size_t count, const char* buffer);
TASK3_API bool InputArrayFromFile(double* arr, size_t count, const char* fileName);
TASK3_API bool OutputArrayToStr(double* arr, size_t count, char* buffer, size_t sizeOfBuf);
TASK3_API bool OutputArrayToFile(double* arr, size_t count, const char* fileName);
TASK3_API double** DynamicArray(double* staticArray2, size_t countOfRows, size_t countOfColomns);