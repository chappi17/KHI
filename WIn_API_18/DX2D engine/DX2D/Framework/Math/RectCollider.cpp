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
	if (pos._x < Left() || pos._x > Right())
		return false;
	if (pos._y > Top() || pos._y < Bottom())
		return false;
	return true;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	return AABB(circle);
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> rect)
{	
	return AABB(rect);
}

bool RectCollider::AABB(shared_ptr<RectCollider> rect)
{
	if (rect->Left() < Right() && rect->Right() > Left() &&
		rect->Bottom() < Top() && rect->Top() > Bottom())
	{
		return true;
	}

	return false;
}

bool RectCollider::AABB(shared_ptr<CircleCollider> circle)
{
		if (IsCollision(circle->_transform->GetWorldPos()))
		return true;

	if ((circle->_transform->GetWorldPos()._x > Left() && circle->_transform->GetWorldPos()._x < Right())
		|| (circle->_transform->GetWorldPos()._y < Top() && circle->_transform->GetWorldPos()._y > Bottom()))
	{
		if (circle->_transform->GetWorldPos()._x < Left() - circle->GetRadius() || circle->_transform->GetWorldPos()._x > Right() + circle->GetRadius())
			return false;
		if (circle->_transform->GetWorldPos()._y > Top() + circle->GetRadius() || circle->_transform->GetWorldPos()._y < Bottom() - circle->GetRadius())
			return false;

		return true;
	}

	if (circle->IsCollision(Vector2(Right(), Top())))
		return true;
	if (circle->IsCollision(Vector2(Left(), Top())))
		return true;
	if (circle->IsCollision(Vector2(Right(), Bottom())))
		return true;
	if (circle->IsCollision(Vector2(Left(), Bottom())))
		return true;

	return false;
}

bool RectCollider::OBB(shared_ptr<RectCollider> rect)
{
	return false;
}



void RectCollider::CreateVertices()
{	
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
