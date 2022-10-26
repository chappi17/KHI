#pragma once
class RectCollider
{
public:
	RectCollider();
	RectCollider(Vector2 center, Vector2 size);

	void Update();
	void Render(HDC hdc);

	Vector2& GetCenter() { return _center; }

private:
	Vector2 _center = Vector2();
	Vector2 _size = Vector2();

	// left top right bottom
	// 중점
	// 가로 세로 길이
};

