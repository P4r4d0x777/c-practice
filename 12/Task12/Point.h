#pragma once
#include "Task12Api.hpp"
#include <iostream>
#include "UnionSystems.h"
class Point // Вариант №4
{
public:
	POINT_API ~Point();
	POINT_API Point();
	POINT_API Point(float firstCoord, float secondCoord,const char* nameOfSystem);
	POINT_API Point(Point&& other) noexcept;
	POINT_API Point(const Point& other);
	POINT_API Point& operator= (const Point& other);
	POINT_API Point& operator= (Point&& other);
	POINT_API friend float operator-(const Point& first, const Point& second);
	POINT_API bool operator==(const Point& right) const;
	POINT_API friend std::ostream& operator<< (std::ostream& out, const  Point& point);
	POINT_API friend std::istream& operator>> (std::istream& in, Point& point);

	POINT_API void SetX(float x);
	POINT_API void SetY(float y);
	POINT_API void SetR(float r);
	POINT_API void SetPolarAngle(float polarAngle);
	POINT_API float GetX();
	POINT_API float GetY();
	POINT_API float GetR();
	POINT_API float GetPolarAngle();
	POINT_API const char* GetNameOfCoords() const;

	POINT_API void ConvertToCartesian();
	POINT_API void ConvertToPolar();
	POINT_API void MoveX(float x);
	POINT_API void MoveY(float y);
	POINT_API static int getCount();
private:
	static size_t count;
	Systems coords;
	char _data[10];
};