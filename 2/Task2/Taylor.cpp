#include "pch.h"
#include "Taylor.h"
#include <cmath>
#include "iostream"
#include <iomanip>
using namespace std;
//при вычислении T - (некоторого множителя), получилась формула: T = x^2 * (2k-1)/ (2k + 1)
float Taylor(float epsilon, float x, int* steps)
{
	float sum = 2 * x;
	float f1 = 2 * x;
	float f2;
	while (abs(f1) >= epsilon)
	{
		*steps = *steps + 1;
		f2 = f1 * (pow(x, 2)) * (2 * (*steps) - 1) / (2 * (*steps) + 1);
		sum += f2;
		f1 = f2;
	}
	return sum;
}