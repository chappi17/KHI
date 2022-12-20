#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
	_type = ColliderType::RECT;
	CreateVertices();
}

RectCollider::RectCollider(Vector2 size)
: _size(size)
{
	_type = ColliderType::RECT;
	CreateVertices();
}

RectCollider::~RectCollider()
{
}

bool RectCollider::IsCollision(Vector2 pos)
{
	if (pos._x >= this->LeftTop()._x && pos._x <= this->RightBottom()._x)
	{
		if (pos._y >= this->LeftTop()._y && pos._y <= this->RightBottom()._y)
		{
			return true;
		}
	}
	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	return circle->IsCollision(shared_from_this());
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> rect)
{	
	return AABB(rect);
}

bool RectCollider::AABB(shared_ptr<RectCollider> other)
{
	//Vector2 leftTop = other->LeftTop();
	//Vector2 leftBottom = Vector2(other->LeftTop()._x, other->RightBottom()._y);
	//Vector2 rightTop = Vector2(other->RightBottom()._x, other->LeftTop()._y);
	//Vector2 rightBottom = other->RightBottom();

	//if (IsCollision(leftTop) || IsCollision(leftBottom) || IsCollision(rightTop) || IsCollision(rightBottom))
	//	return true;

	//return false;

	if (this->IsCollision(other->LeftTop()) == true)
	{
		return true;
	}
	if (this->IsCollision(other->RightBottom()) == true)
	{
		return true;
	}
	if (this->IsCollision(Vector2(other->LeftTop()._x, other->RightBottom()._y)) == true)
	{
		return true;
	}
	if (this->IsCollision(Vector2(other->RightBottom()._x, other->LeftTop()._y)) == true)
	{
		return true;
	}
	return false;
}


bool RectCollider::OBB(shared_ptr<RectCollider> rect)
{
	return false;
}

Vector2 RectCollider::LeftTop()
{
	Vector2 result;
	Vector2 half = GetWorldSize() * 0.5f;

	result._x = _transform->GetWorldPos()._x - half._x;
	result._y = _transform->GetWorldPos()._y + half._y;

	return result;
}

Vector2 RectCollider::RightBottom()
{
	Vector2 result;
	Vector2 half = GetWorldSize() * 0.5f;
	result._x = _transform->GetWorldPos()._x + half._x;
	result._y = _transform->GetWorldPos()._y - half._y;

	return result;
}

Vector2 RectCollider::GetWorldSize()
{
	Vector2 result;

	XMFLOAT4X4 matrix;
	XMStoreFloat4x4(&matrix, *_transform->GetMatrix());

	result._x = _size._x * matrix._11;
	result._y = _size._y * matrix._22;

	return result;
}



void RectCollider::CreateVertices()
{	
	Vector2 halfSize = _size * 0.5f;
	// 왼쪽 위
	_vertices.emplace_back(-halfSize._x, halfSize._y);
	// 오른쪽 위
	_vertices.emplace_back(halfSize._x, halfSize._y);
	// 오른쪽 아래
	_vertices.emplace_back(halfSize._x, -halfSize._y);
	// 왼쪽 아래
	_vertices.emplace_back(-halfSize._x, -halfSize._y);
	// 왼쪽 위
	_vertices.emplace_back(-halfSize._x, halfSize._y);

	Collider::CreateData();

	_colorBuffer->_data.color = { 0.0f,1.0f,0.0f,1.0f };
}
