#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	_pens[0] = CreatePen(0, 3, RED);
	_pens[1] = CreatePen(0, 3, GREEN);
	_curPen = _pens[1];
}

CircleCollider::CircleCollider(Vector2 center, float radius)
: _center(center)
, _radius(radius)
{
	_pens[0] = CreatePen(0, 3, RED);
	_pens[1] = CreatePen(0, 3, GREEN);
	_curPen = _pens[1];
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);
	float left = _center._x - _radius;
	float right = _center._x + _radius;
	float top = _center._y - _radius;
	float bottom = _center._y + _radius;
	Ellipse(hdc, left, top, right, bottom);
}

void CircleCollider::SetRED()
{
	_curPen = _pens[0];
}

void CircleCollider::SetGREEN()
{
	_curPen = _pens[1];
}

bool CircleCollider::IsCollision(Vector2 pos)
{
	float lengthAToB = _center.Length(pos);
	if (lengthAToB <= _radius)
		return true;

	return false;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float lengthAToB = _center.Length(other->GetCenter());
	if (lengthAToB <= _radius + other->GetRadius())
		return true;

	return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect)
{
	// return rect->IsCollision()
	return false;
}
