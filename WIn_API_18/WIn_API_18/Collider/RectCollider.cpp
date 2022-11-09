#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
	_type = ColliderType::RECT;
}

RectCollider::RectCollider(Vector2 center, Vector2 size)
: _size(size)
{
	_type = ColliderType::RECT;
	_center = center;
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	//SelectObject(hdc, _curPen);
	float left = _center._x - (_size._x * 0.5f);
	float right = _center._x + (_size._x * 0.5f);
	float top = _center._y + (_size._y * 0.5f);
	float bottom = _center._y - (_size._y * 0.5f);
	Rectangle(hdc, left, top, right, bottom);

}

bool RectCollider::IsCollision(Vector2 pos)
{

	float left = _center._x - (_size._x * 0.5f);
	float right = _center._x + (_size._x * 0.5f);
	float top = _center._y - (_size._y * 0.5f);
	float bottom = _center._y + (_size._y * 0.5f);

	if (pos._x >= left && pos._x <= right &&
		pos._y >= top && pos._y <= bottom)
		return true;
	return false;
}

Vector2 RectCollider::LeftTop()
{
	float left = _center._x - (_size._x * 0.5f);
	float top = _center._y - (_size._y * 0.5f);

	return Vector2(left, top);
}

Vector2 RectCollider::RightBottom()
{
	float right = _center._x + (_size._x * 0.5f);
	float bottom = _center._y + (_size._y * 0.5f);

	return Vector2(right, bottom);

}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	float left = LeftTop()._x;
	float right = RightBottom()._x;
	float top = LeftTop()._y;
	float bottom = RightBottom()._y;

	Vector2 center = circle->GetCenter();
	float radius = circle->GetRadius();

	if (center._x >= left && center._x <= right
		&& center._y >= top - radius && center._y <= bottom + radius)
		return true;

	if (center._x >= left - radius && center._x <= right + radius
		&& center._y >= top && center._y <= bottom)
		return true;

	if (circle->IsCollision(LeftTop()) || circle->IsCollision(RightBottom())
		|| circle->IsCollision(Vector2(left, bottom)) || circle->IsCollision(Vector2(right, top)))
		return true;

	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	Vector2 leftTop = other->LeftTop();
	Vector2 leftBottom = Vector2(other->LeftTop()._x, other->RightBottom()._y);
	Vector2 rightTop = Vector2(other->RightBottom()._x, other->LeftTop()._y);
	Vector2 rightBottom = other->RightBottom();

	if (IsCollision(leftTop) || IsCollision(leftBottom) || IsCollision(rightTop) || IsCollision(rightBottom))
		return true;

	return false;
}

