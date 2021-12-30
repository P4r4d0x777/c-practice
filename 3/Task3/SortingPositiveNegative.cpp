#include "pch.h"
#include "SortingPositiveNegative.h"
// ������� ������������� ��� �������������, ����� ��� �������������
// � ������� ��������
double *SortingPositiveNegative(double* arr, size_t count)
{
	// ��� � ���� ������ ����������, ������� ���������� ��������� �� ������ (�� ���� �� ������� 1 2 -3 4 -7 5 -6 8 ������ ���������� 1 2 4 5 8 -3 -7 -6)
	double k;
	while (!LastNumbersNegative(arr, count))
	{
		for (int i = count - 1;i >= 1;i--)
		{
			if (arr[i] > 0 & arr[i - 1] < 0)
			{
				k = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = k;
			}
			else
				continue;
		}
	}
	return arr;
}
// ������� ��������� ���� ���������� �������� - ��������� � �����
bool ArraysAreEqual(double* arr1, double* arr2, size_t count)
{
	if (arr1 == nullptr || arr2 == nullptr)
		return false;
	for (size_t i = 0; i < count; ++i)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}
bool LastNumbersNegative(const double* arr, size_t count)
{
	// ��������� ���������� �������� �� �������� �����
	int countOfNegative = 0;
	for (int i = 0;i < count;i++)
	{
		if (arr[i] < 0)
			countOfNegative++;
	}
	int NegativeInLast = 0;
	for (int i = count - countOfNegative;i < count;i++)
	{
		if (arr[i] < 0)
			NegativeInLast++;
	}
	if (NegativeInLast == countOfNegative)
		return true;
	return false;
}