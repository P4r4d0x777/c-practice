#include "pch.h" 
#include "../Task10/TemplArrayFunc.h"
#include <cstdlib> 
#include <ctime>
#include <string>
#define SIZE 5
TEST(ChangeTests, ChangeArr_INT)
{
	int numbers[7] = { 1,2,3,4,5,6,7 };
	const int res_numbers[7] = { 2,3,4,5,6,7,8 };
	ChangeElements<7>(numbers);
	for (size_t i = 0; i < 7;i++)
		ASSERT_EQ(numbers[i], res_numbers[i]);
}
TEST(ChangeTests, ChangeArr_DOUBLE)
{
	double numbers[7] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7 };
	const double res_numbers[7] = { 2.2,3.3,4.4,5.5,6.6,7.7,8.8 };
	ChangeElements<7>(numbers);
	for (size_t i = 0; i < 7;i++)
		ASSERT_EQ(floor(numbers[i]), floor(res_numbers[i]));
}
TEST(MaxOfAllTests, ReturnMax_INT)
{
	int numbers[3] = { 1,2,3 };
	ASSERT_EQ(3, Maximum(numbers,3));
}
TEST(MaxOfAllTests, ReturnMax_DOUBLE)
{
	double numbers[3] = { 1.123,2.233,3.344 };
	ASSERT_EQ(floor(3.344), floor(Maximum(numbers, 3)));
}
TEST(MaxOfAllTests, ReturnMax_CHAR)
{
	const char *people[3] = { "Leonardo", "BillGates", "LeonardoDiCaprio" };
	ASSERT_STREQ(people[2], Maximum(people,3));
}
TEST(SumTests, SumOfAllElements_INT)
{
	int numbers[3] = { 1,2,3 };
	ASSERT_EQ(6, Sum(numbers, 3));
}
TEST(SumTests, SumOfAllElements_DOUBLE)
{
	double numbers[3] = { 1.1,2.2,3.3 };
	ASSERT_EQ(floor(6.6), floor(Sum(numbers, 3)));
}
TEST(SumTests, SumOfAllElements_CHAR)
{
	const char* people[3] = { "Leonardo", "BillGates", "LeonardoDiCaprio" };
	ASSERT_STREQ("LeonardoBillGatesLeonardoDiCaprio", Sum(people, 3));
}
TEST(ChangeArrTests, ChangeArr_INT)
{
	int* arrInt = new int[SIZE];
	for (size_t i = 0; i < SIZE; ++i)
	{
		arrInt[i] = rand() * 200 / RAND_MAX; 
	}
	int arrRes [SIZE + 2];
	for (size_t i = 0; i < SIZE; ++i)
	{
		arrRes[i] = arrInt[i];
	}
	arrRes[SIZE] = Maximum(arrInt, SIZE);
	arrRes[SIZE + 1] = Sum(arrInt, SIZE);
	arrInt = ChangeArr(arrInt, SIZE);
	for (size_t i = 0; i < SIZE; ++i)
	{
		ASSERT_EQ(arrInt[i], arrRes[i]);
	}
}
TEST(ChangeArrTests, ChangeArr_DOUBLE)
{
	double* arrDouble = new double[SIZE];
	for (size_t i = 0; i < SIZE; ++i)
	{
		arrDouble[i] = (1000 - 5) * static_cast<double>(rand()) / RAND_MAX + 5;
	}
	double arrRes[SIZE + 2];
	for (size_t i = 0; i < SIZE; ++i)
	{
		arrRes[i] = arrDouble[i];
	}
	arrRes[SIZE] = Maximum(arrDouble, SIZE);
	arrRes[SIZE + 1] = Sum(arrDouble, SIZE);
	arrDouble = ChangeArr(arrDouble, SIZE);
	for (size_t i = 0; i < SIZE; ++i)
	{
		ASSERT_EQ(arrDouble[i], arrRes[i]);
	}
}
