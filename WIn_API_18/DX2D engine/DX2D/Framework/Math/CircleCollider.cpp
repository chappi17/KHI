#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	_type = ColliderType::CIRCLE;
	CreateVertices();
}

CircleCollider::CircleCollider(float radius)
: _radius(radius)
, dot(36)
{
	_type = ColliderType::CIRCLE;
	CreateVertices();
}

CircleCollider::~CircleCollider()
{
}

bool CircleCollider::IsCollision(Vector2 pos)
{
	if ((this->GetTransform()->GetWorldPos() - pos).Length() <= (this->GetWorldRadius()))
	{
		return true;
	}
	return false;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	if ((this->GetTransform()->GetWorldPos() - other->GetTransform()->GetWorldPos()).Length() <= (this->GetWorldRadius() + other->GetWorldRadius()))
	{
		return true;
	}
	return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect)
{
	Vector2 temp = rect->GetWorldSize();
	float left = rect->LeftTop()._x;
	float right = rect->RightBottom()._x;
	float top = rect->LeftTop()._y;
	float bottom = rect->RightBottom()._y;

	Vector2 center = _transform->GetWorldPos();
	float radius = GetWorldRadius();

	if (center._x >= left && center._x <= right
		&& center._y <= top + radius && center._y >= bottom - radius)
		return true;

	if (center._x >= left - radius && center._x <= right + radius
		&& center._y <= top && center._y >= bottom)
		return true;

	if (IsCollision(rect->LeftTop()) || IsCollision(rect->RightBottom())
		|| IsCollision(Vector2(left, bottom)) || IsCollision(Vector2(right, top)))
		return true;

	return false;
}

float CircleCollider::GetWorldRadius()
{
	XMFLOAT4X4 matrix;
	XMStoreFloat4x4(&matrix, *_transform->GetMatrix());

	return _radius * __max(matrix._11, matrix._22);
}

void CircleCollider::CreateVertices()
{
	// cos theta = x / r
	// sin theta = y / r

	// x = cos theta * r
	// y = sin theta * r

	float theta = 2.0f * PI /dot;

	for (int i = 0; i <= dot; i++)
	{
		_vertices.emplace_back(cos(theta * i) * _radius, sin(theta * i) * _radius);
	}
		Collider::CreateData();
		_colorBuffer->_data.color = { 0.0f,1.0f,0.0f,1.0f };	
}
