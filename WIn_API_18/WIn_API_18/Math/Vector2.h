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


	// ���� 
	//Vector2 Dot(const Vector2& other);
	//Vector2 Cross(const Vector2& other);

	// ��¥ �߿��Ѱ�
	// ����ȭ : � �� ���͸� ���̰� 1�� ���ͷ� ����� �۾� (�Ʒ���)
	// ���� ���� : ���̰� 1�� ���� -> 2���� ��Ʈ 2
	// �� ���Ҹ� ���̷� ����������.

	// ���ʹ� ���� ����
	// ��Į��� ��

	float Length();
	float Length(const Vector2& other);
	Vector2 Normalize();



	float _x = 0.0f;
	float _y = 0.0f;
};

