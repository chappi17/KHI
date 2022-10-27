#pragma once
class RectCollider;

class CircleCollider
{
public:
	CircleCollider();
	~CircleCollider();

	CircleCollider(Vector2 center, Vector2 size);
	CircleCollider(Vector2 center, float radius);

	void Update();
	void Render(HDC hdc);

	void SetRED();
	void SetGREEN();

	const Vector2& GetCenter() { return _center; }
	const float& GetRadius() { return _radius; }

	void SetCenter(const Vector2& center) { _center = center; }
	void SectRadius(const float& value) { _radius = value; } 

	bool IsCollision(Vector2 pos);
	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr<RectCollider> rect);

private:
	HPEN _curPen;
	HPEN _pens[2];

	Vector2 _center = Vector2(0,0);
	Vector2 _size = Vector2();

	float _radius;

};

