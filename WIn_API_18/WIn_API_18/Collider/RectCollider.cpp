#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
}

RectCollider::RectCollider(Vector2 center, Vector2 size)
:_center(center), _size (size)
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	float left = _center._x - (_size._x * 0.5f);
	float right = _center._x + (_size._x * 0.5f);
	float top = _center._y + (_size._y * 0.5f);
	float bottom = _center._y - (_size._y * 0.5f);
	Rectangle(hdc, left, top, right, bottom);

}
