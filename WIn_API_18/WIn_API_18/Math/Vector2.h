#pragma once
class Vector2
{
public:
	Vector2() {}
	Vector2(float x, float y) : _x(x), _y(y) {}

	Vector2 operator+(const Vector2& other);
	Vector2& operator+=(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2 operator*(const float& value);
	Vector2 operator/(const float& value);


	// 과제 
	Vector2 Dot(const Vector2& other1, Vector2& other2);
	Vector2 Cross(const Vector2& other1, Vector2& other2, Vector2& other3);


	// 진짜 중요한거
	// 정규화 : 어떤 한 벡터를 길이가 1인 벡터로 만드는 작업 (아래꺼)
	// 단위 벡터 : 길이가 1인 벡터 -> 2분의 루트 2
	// 각 원소를 길이로 나눠버린다.

	// 벡터는 힘과 방향
	// 스칼라는 힘

	float Length();
	float Length(const Vector2& other);
	float Rec_center(float& other);

	Vector2 Normalize();
	float Area();


	float _x = 0.0f;
	float _y = 0.0f;
};

