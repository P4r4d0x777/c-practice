#include "pch.h" 
#include "../Task3/AbsSumLeftPositive.h"
#include "../Task3/io.h" // C�������� ���� ��� �����/������ � ������ ��� ��������� ���� 
#include <math.h>
// ������������ ������� ���������� ����� ������� ��������� �������,
// ������������� �� ���������� �������������� ��������
TEST(Var4_�1_1_Tests, AbsSumLeftPositive)
{
	const size_t n = 5;
	double arr[n] = { 1.3, 2.21, -3.0, 4.8, 5.55 };
	ASSERT_EQ(floor(11.31), floor(AbsSumLeftPositive(arr, 5)));
}
TEST(Var4_�1_1_Tests, AbsSumLeftPositiveEqualNull)
{
	const size_t n = 5;
	double arr[n] = { -1.3, -2.21, -3.0, -4.8, -5.55 };
	ASSERT_EQ(0, floor(AbsSumLeftPositive(arr, 5)));
}

TEST(Var4_�1_1_Tests, AbsSumLeftPositiveFromFile)
{
	const size_t n = 5;
	double arr1[n] = { 1.3, 2.21, -3.0, 4.8, 5.55 };
	ASSERT_TRUE(OutputArrayToFile(arr1, n, "Sum.txt"));
	double arr2[n] = { 0 };
	ASSERT_TRUE(InputArrayFromFile(arr2, n, "Sum.txt"));
	ASSERT_EQ(floor(11.31), floor(AbsSumLeftPositive(arr2, 5)));
}
// �� ����� ����� ������ ������� �����, � ������������ �������� sum ����� �� 11.3100... ��� ������, � 11.3099999...
// �������� ���������� floor