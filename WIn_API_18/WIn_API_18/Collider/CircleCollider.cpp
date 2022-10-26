#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
}

CircleCollider::CircleCollider(Vector2 center, Vector2 size)
	:_center(center), _size(size)
{
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	float left = _center._x - (_size._x * 0.5f);
	float right = _center._x + (_size._x * 0.5f);
	float top = _center._y + (_size._y * 0.5f);
	float bottom = _center._y - (_size._y * 0.5f);
	Ellipse(hdc, left, top, right, bottom);

}
