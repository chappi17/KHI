#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{	
	_type = ColliderType::CIRCLE;
}

CircleCollider::CircleCollider(Vector2 center, float radius)
	: _radius(radius)
{	
	_center = center;
	_type = ColliderType::CIRCLE;
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
	return rect->IsCollision(shared_from_this());
}
