#include "pch.h"
bool InputArrayFromStream(double* arr, size_t count, std::istream& inpStream)
{
	if (!inpStream)
		return false;
	for (size_t i = 0; i < count; ++i)
		inpStream >> arr[i];
	return true;
}
// ����� ������������� ������� � ����� ������.
bool OutputArrayToStream(double* arr, size_t count, std::ostream& outStream)
{
	if (!outStream)
		return false;
	for (size_t i = 0; i < count; ++i)
		outStream << arr[i] << ' ';
	return true;
}
// ����� ������������� ������� � ��������� ����.
bool OutputArrayToFile(double* arr, size_t count, const char* fileName)
{
	std::ofstream outFile(fileName); // �������� ����� ��� ������
	if (!outFile)
		return false; // ����� �� �������, ���� �� ������ ����
	return OutputArrayToStream(arr, count, outFile);
}
// ����� ������������� ������� � ��������� �����.
bool OutputArrayToStr(double* arr, size_t count, char* buffer, size_t sizeOfBuf)
{
	std::ostrstream outStr(buffer, sizeOfBuf); // �������� ���������� ������ ��� ������
	return OutputArrayToStream(arr, count, outStr);
}
// ���� ������������� ������� �� ���������� ������.
bool InputArrayFromStr(double* arr, size_t count, const char* buffer)
{
	std::istrstream inpStr(buffer); // �������� ���������� ������ ��� �����
	return InputArrayFromStream(arr, count, inpStr);
}
bool InputArrayFromFile(double* arr, size_t count, const char* fileName)
{
	std::ifstream inpFile(fileName); // �������� ���������� ����� ��� �����
	return InputArrayFromStream(arr, count, inpFile);
}
// �������������� ������������� ���������� ������������ ������� � ������������
double** DynamicArray(double* staticArray2, size_t countOfRows, size_t countOfColomns)
{
	double** dynamicArray2 = new double* [countOfRows];
	for (size_t i = 0; i < countOfRows; ++i)
	{
		dynamicArray2[i] = new double[countOfColomns];
		for (size_t j = 0; j < countOfColomns; ++j)
			dynamicArray2[i][j] = staticArray2[i * countOfColomns + j];
	}
	return dynamicArray2;
}