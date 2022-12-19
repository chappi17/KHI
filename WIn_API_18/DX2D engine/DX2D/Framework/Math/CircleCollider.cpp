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
	float distance = _transform->GetWorldPos().Length(pos);
	float radius = GetRadius();
	if (distance < radius)
		return true;

	return false;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float lengthAToB = _transform->GetWorldPos().Length(other->GetCenter());
	if (lengthAToB <= _radius + other->GetRadius())
		return true;

	return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect)
{
	return rect->IsCollision(shared_from_this());
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
