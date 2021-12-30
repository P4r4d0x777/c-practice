#include "pch.h"
#include "Logarithm.h"
#include <cmath>

int Logarithm(int LogarithmParameter)
{
	if (LogarithmParameter % 2 != 0)
		return -1;
	// неправильно, если я подам, например, число 20, то ваша функция не вернет -1
	if (LogarithmParameter <= 0)
		return -2;
	if (LogarithmParameter % 2 == 0)
	{
		int count = 0;
		int LogarithmParameterCopy = LogarithmParameter;
		while (LogarithmParameterCopy != 1)
		{
			LogarithmParameterCopy = LogarithmParameterCopy / 2;
			count++;
		}
		int isPowerOfTwo = 1;
		for (int i = 0; i < count; i++)
			isPowerOfTwo = isPowerOfTwo * 2;
		if (isPowerOfTwo != LogarithmParameter)
			return -1;
		return count;
	}
}


