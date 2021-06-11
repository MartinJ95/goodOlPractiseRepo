#include "pch.h"
#include <math.h>
#include "Vector.h"

Point Point::AddVector(Vector v)
{
	Point p2;

	p2.x = x + v.x;
	p2.y = y + v.y;

	return p2;
}

float Vector::Length() const
{
	float length;

	length = sqrt(x*x + y*y);

	return length;
}

float Vector::LengthSqr() const
{
	float length;

	length = (x*x + y*y);

	return length;
}