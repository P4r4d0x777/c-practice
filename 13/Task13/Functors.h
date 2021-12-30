#pragma once
//#include "Task13Api.hpp"
#include "pch.h"
#include <cmath>
#include "CorrectPyramid.h"
class FunctorInteger
{
public:
	bool operator()(int first, int second) const
	{
		return first == second;
	}
};

class FunctorDouble
{
public:
	bool operator()(double first, double second) const
	{
		return abs(first) - abs(second) < .00000001;
	}
};

class FunctorPyramidArea
{
public:
	bool operator()(double area, CorrectPyramid SABCD)
	{
		double areaOfSABCD = (4 * SABCD.squareSize) / 2 * (SABCD.squareSize / 2 + sqrt(pow(SABCD.height, 2) + pow(SABCD.squareSize / 2, 2)));
		return abs(area) - areaOfSABCD < .00000001;
	}
};