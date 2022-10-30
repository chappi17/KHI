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

Vector2 Vector2::Dot(const Vector2& other1, Vector2& other2)
{
	float result = 0.0f;
	float v = ((other1._x * other2._y) + (other1._x * other2._y));
	float degree = v * (180 / 3.1415);

	return Vector2();
}

Vector2 Vector2::Cross(const Vector2& other1, Vector2& other2, Vector2& other3)
{
	float result = 0.0f;
	Vector2 x = { other2._x - other1._x, other2._y - other1._y };
	Vector2 y = { other3._x - other1._x, other3._y - other1._y };
	result = { ((float)x._x * y._y) - ((float)x._y * y._x) };

	return Vector2();
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

float Vector2::Rec_center(float& other)
{
	float temp_x = (other + _x) / 2;
	float temp_y = (other + _y) / 2;
	return (temp_x, temp_y);
}

Vector2 Vector2::Normalize()
{
	float length = this->Length();
	return Vector2(_x /length, _y/length);
}
