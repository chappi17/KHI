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
	return rect->IsCollision(shared_from_this());
}

bool CircleCollider::OBB(shared_ptr<CircleCollider> circle)
{
	return IsCollision(circle);
}

bool CircleCollider::OBB(shared_ptr<RectCollider> rect)
{
	return rect->OBB(shared_from_this());
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
