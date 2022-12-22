#pragma once
class Vector2
{
public:
	Vector2() {}
	Vector2(int x, int y) : _x(float(x)), _y(float(y)) {}
	Vector2(float x, float y) : _x(x), _y(y) {}

	Vector2 operator+(const Vector2& other) const;
	Vector2& operator+=(const Vector2& other);
	Vector2 operator-(const Vector2& other) const;
	Vector2& operator-=(const Vector2& other);
	Vector2 operator*(const float& value) const;
	Vector2& operator*=(const float& value);
	Vector2 operator/(const float& value) const;

	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;

	bool operator>(const Vector2& other) const;
	bool operator<(const Vector2& other) const;

	float Dot(const Vector2& other);
	float Cross(const Vector2& other);
	bool IsBetween(const Vector2& vector1, const Vector2& vector2);

	float Length() const;
	float Length(const Vector2& other) const;
	void Normallize();

	Vector2 Normal() const;

	int Manhattan(const Vector2& other);

	float Angle() const;

	float _x = 0.0f;
	float _y = 0.0f;
};