#include "pch.h"
#include "GCD.h"
#include <math.h>
int RecursiveGCD(int a, int b)
{
	return b == 0 ? abs(a) : RecursiveGCD((b), (a) % (b)); // если a < b то просто поменяет их местами
}
int GCD(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (abs(a) > abs(b))
			a %= b;
		else
			b %= a;
	}
	return abs(a + b);
}
