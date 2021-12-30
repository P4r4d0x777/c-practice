#include "pch.h"
#include "../Task10/TemplArraySortWithMakro.h"
#define SIZE 7
TEMPLATE_SORT(double); 
TEMPLATE_SORT(int);
TEST(TEMPLATE_SORT_Tests, TEMPLATE_SORT_intTest)
{
	int arrInt[SIZE] = { 5, 8, 1, 4, 9, 2, 3 };
	int arrResInt[SIZE] = { 9,8,5,4,3,2,1 };
	Sort_int(arrInt, SIZE);
	for (int i = 0; i < SIZE; i++)
		ASSERT_EQ(arrInt[i], arrResInt[i]);

}
TEST(TEMPLATE_SORT_Tests, TEMPLATE_SORT_doubleTest)
{
	double arrDouble[SIZE] = { 5.5, 8.8, -1.1, -4.4, 9.9, 2.2, -3.3 };
	double arrResDouble[SIZE] = { 9.9,8.8,5.5,2.2,-1.1,-3.3,-4.4 };
	Sort_double(arrDouble, SIZE);
	for (int i = 0; i < SIZE; i++)
		ASSERT_EQ(arrDouble[i], arrResDouble[i]);
}