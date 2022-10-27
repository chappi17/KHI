#pragma once
class RectCollider
{
public:
	RectCollider();
	RectCollider(Vector2 center, Vector2 size);

	void Update();
	void Render(HDC hdc);

	Vector2& GetCenter() { return _center; }

	bool IsCollision(const Vector2& pos);
	bool IsCollision(shared_ptr<CircleCollider> circle);
	bool Iscollision(shared_ptr<RectCollider> other);

private:
	Vector2 _center = Vector2();
	Vector2 _size = Vector2();

	// left top right bottom
	// 중점
	// 가로 세로 길이
};

