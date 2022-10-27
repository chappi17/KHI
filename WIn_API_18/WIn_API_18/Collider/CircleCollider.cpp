#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	_pens[0] = CreatePen(0, 3, RED);
	_pens[1] = CreatePen(0, 3, GREEN);
	_curPen = _pens[1];
}


CircleCollider::CircleCollider(Vector2 center, Vector2 size)
	:_center(center), _size(size)
{
	_pens[0] = CreatePen(0, 3, RED);
	_pens[1] = CreatePen(0, 3, GREEN);
	_curPen = _pens[1];
}

CircleCollider::CircleCollider(Vector2 center, float radius)
	: _center(center), _radius(0)
{
}

CircleCollider::~CircleCollider()
{
}

//CircleCollider::CircleCollider(Vector2 center, float radius)
//	
//{
//}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curPen);
	float left = _center._x - (_size._x * 0.5f);
	float right = _center._x + (_size._x * 0.5f);
	float top = _center._y + (_size._y * 0.5f);
	float bottom = _center._y - (_size._y * 0.5f);
	Ellipse(hdc, left, top, right, bottom);

	//float left = _center._x - _radius;
	//float right = _center._x + _radius;
	//float top = _center._x - _radius;
	//float bottom = _center._x + _radius;
	//Ellipse(hdc, left, top, right, bottom);

}

void CircleCollider::SetRED()
{
	_curPen = _pens[0];
}

void CircleCollider::SetGREEN()
{
	_curPen = _pens[1];
}

bool CircleCollider::IsCollision(Vector2 pos)
{
	float lengthATOB = _center.Length(pos);
	// if (lengthATOB <= _radius) -> circle ���������� �ٲ��� 
	return true;

	return false;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float lengthATOB = _center.Length(other->GetCenter()); // �� ���� �߽ɰ��� �Ÿ�
	if (lengthATOB < _radius + other->GetRadius());
		return true;
	return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect)
{
	//return rect->IsCollision()
	return false;
}
