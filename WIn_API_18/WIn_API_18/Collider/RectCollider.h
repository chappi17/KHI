#pragma once
class CircleCollider;

class RectCollider
{
public:
	RectCollider();
	RectCollider(Vector2 center, Vector2 size);

	void Update();
	void Render(HDC hdc);

	void SetRED();
	void SetGREEN();

	Vector2& GetCenter() { return _center; }
	Vector2& GetSize() { return _size; }

	bool IsCollision(const Vector2& pos);
	bool IsCollision(shared_ptr<CircleCollider> circle);
	bool Iscollision(shared_ptr<RectCollider> other);

private:
	HPEN _curPen;
	HPEN _pens[2];


	Vector2 _center = Vector2(0,0);
	Vector2 _size = Vector2(0,0);
	Vector2 _area = Vector2(0,0);
	

	// left top right bottom
	// 중점
	// 가로 세로 길이
};

