#pragma once
class Vector
{
public:
	float Length() const;
	float LengthSqr() const;

	float x, y;
};

class Point
{
public:
	Point AddVector(Vector v);

	float x, y;

Vector operator-(Point b)
{
	Vector v;

	v.x = x - b.x;
	v.y = y - b.y;

	return v;
}
};

