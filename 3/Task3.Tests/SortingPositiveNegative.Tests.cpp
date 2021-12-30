#include "pch.h" 
#include "../Task3/SortingPositiveNegative.h"

TEST(Var4_¹1_2_Tests, SortingPositiveNegative_1)
{
	const size_t n = 5;
	double arr[n] = { 1.3, 2.21, -3.0, 4.8, 5.55 };
	double result[n] = { 1.3, 2.21, 4.8, 5.55 ,- 3.0};
	ASSERT_TRUE(ArraysAreEqual(result, SortingPositiveNegative(arr,n),n));
}
TEST(Var4_¹1_2_Tests, ArraysAreEqual)
{
	const size_t n = 8;
	double arr[n] = { 1,2,-3,4,-7,5,-6,8 };
	double result[n] = { 1,2,-3,4,-7,5,-6,8 };
	ASSERT_TRUE(ArraysAreEqual);
}
TEST(Var4_¹1_2_Tests, SortingPositiveNegative_2)
{
	const size_t n = 8;
	double arr[n] = { 1,2,-3,4,-7,5,-6,8 };
	double result[n] = { 1,2,4,5,8,-3,-7,-6 };
	ASSERT_TRUE(ArraysAreEqual(result, SortingPositiveNegative(arr, n), n));
}