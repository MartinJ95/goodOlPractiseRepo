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

Vector Point::operator-(Point b)
{
	Vector v;

	v.x = x - b.x;
	v.y = y - b.y;

	return v;
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

Vector Vector::ConvertToSF()
{
	return Vector2f(x,y);
}

Vector Vector::Normalized() const
{
	Vector normalized;

	normalized = (*this) / Length();

	return normalized;
}

Vector Vector::operator-(const Vector& v) const
{
	return Vector(x - v.x, y - v.y);
}

Vector Vector::operator+(const Vector& v) const
{
	return Vector(x + v.x, y + v.y);
}

Vector Vector::operator/(float s) const
{
	Vector scaled;

	scaled.x = x / s;
	scaled.y = y / s;

	return scaled;
}