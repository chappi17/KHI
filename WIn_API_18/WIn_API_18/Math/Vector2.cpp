#include "framework.h"
#include "Vector2.h"

Vector2 Vector2::operator+(const Vector2& other)
{

	return Vector2(_x + other._x , _y + other._y);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	_x += other._x;
	_y += other._y;

	return *this;
}

Vector2 Vector2::operator-(const Vector2& other)
{
	return Vector2(_x - other._x, _y - other._y);
}

Vector2& Vector2::operator-=(const Vector2& other)
{
	_x -= other._x;
	_y -= other._y;

	return *this;
}

Vector2 Vector2::operator*(const float& value)
{
	return Vector2(_x * value, _y * value);
}

Vector2 Vector2::operator/(const float& value)
{
	return Vector2(_x / value, _y / value);
}

float Vector2::Length()
{
	return sqrt(powf(_x, 2) + powf(_y, 2));
}

float Vector2::Length(const Vector2& other)
{

	Vector2 temp = (*this) - other;
	return temp.Length();
}

Vector2 Vector2::Normalize()
{
	float length = this->Length();
	return Vector2(_x /length, _y/length);
}
