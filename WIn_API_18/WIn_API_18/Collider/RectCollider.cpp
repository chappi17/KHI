#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
	_pens[0] = CreatePen(0, 3, RED);
	_pens[1] = CreatePen(0, 3, GREEN);
	_curPen = _pens[1];
}

RectCollider::RectCollider(Vector2 center, Vector2 size)
:_center(center), _size (size)
{
	_pens[0] = CreatePen(0, 3, RED);
	_pens[1] = CreatePen(0, 3, GREEN);
	_curPen = _pens[1];
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);
	float left = _center._x - (_size._x * 0.5f);
	float right = _center._x + (_size._x * 0.5f);
	float top = _center._y + (_size._y * 0.5f);
	float bottom = _center._y - (_size._y * 0.5f);
	Rectangle(hdc, left, top, right, bottom);

}

void RectCollider::SetRED()
{
	_curPen = _pens[0];
}

void RectCollider::SetGREEN()
{
	_curPen = _pens[1];
}

bool RectCollider::IsCollision(const Vector2& pos)
{

	float lengthATOB = _center.Length(pos);
	if (lengthATOB <= _area.Area());
		return true;

	return false;
}
                                                                                                   
bool RectCollider::Iscollision(shared_ptr<RectCollider> other)
{
	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	float lengthAToB = _center.Length(circle->GetCenter());
	if (lengthAToB <= _area.Area() + circle->GetRadius())
		return true;

	return false;
}

