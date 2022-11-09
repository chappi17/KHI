#pragma once
class Vector2
{
public:
	Vector2() {}
	Vector2(float x, float y) : _x(x), _y(y) {}

	Vector2 operator+(const Vector2& other) const;
	Vector2& operator+=(const Vector2& other);
	Vector2 operator-(const Vector2& other) const;
	Vector2& operator-=(const Vector2& other);
	Vector2 operator*(const float& value) const;
	Vector2 operator/(const float& value) const;

	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;

	// 과제
	float Dot(const Vector2& other);
	float Cross(const Vector2& other);
	bool IsBetween(const Vector2& vector1, const Vector2& vector2);

	// 정규화 : 어떤 한 벡터를 길이가 1인 벡터로 만드는 작업
	// 단위 벡터: 길이 1인 벡터
	float Length();
	float Length(const Vector2& other);
	Vector2 Normallize();


	float _x = 0.0f;
	float _y = 0.0f;
};

