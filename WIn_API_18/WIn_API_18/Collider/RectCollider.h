#pragma once
class CircleCollider;

class RectCollider
{
public:
	RectCollider();
	RectCollider(Vector2 center, Vector2 size);
	~RectCollider();

	void Update();
	void Render(HDC hdc);

	void SetRED();
	void SetGREEN();

	Vector2& GetCenter() { return _center; }

	bool IsCollision(Vector2 pos);
	bool IsCollision(shared_ptr<CircleCollider> circle);
	bool IsCollision(shared_ptr<RectCollider> other);

	Vector2 LeftTop();
	Vector2 RightBottom();

private:
	HPEN _curPen;
	HPEN _pens[2];

	Vector2 _center = Vector2();
	Vector2 _size = Vector2();

	// left top right bottom
	// 중점
	// 가로 세로 길이
};

