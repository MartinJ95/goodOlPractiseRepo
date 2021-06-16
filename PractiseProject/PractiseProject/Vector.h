#pragma once
#include "Graphics.h"

using namespace sf;

class Vector
{
public:
	Vector() {}

	Vector(float X, float Y)
	{
		x = X;
		y = Y;
	}

	Vector(Vector2i vector)
	{
		x = vector.x;
		y = vector.y;
	}

	Vector(Vector2f vector)
	{
		x = vector.x;
		y = vector.y;
	}

	float Length() const;
	float LengthSqr() const;

	Vector ConvertToSF();

	Vector Normalized() const;

	Vector operator-(const Vector& v) const;
	Vector operator+(const Vector& v) const;

	Vector operator/(float s) const;

public:
	float x, y;
};

class Point
{
public:
	Point AddVector(Vector v);

	float x, y;

	Vector operator-(Point b);
};