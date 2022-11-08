#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_ball = make_shared<CircleCollider>(Vector2{ CENTER_X, 500 }, 5);	
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if (_isActive == false)
		return;
	
	Vector2 now = _ball->GetCenter();
	now += _dir.Normalize() * _speed;
	_ball->SetCenter(now);


	if (_ball->_center._y <= 0 + _ball->GetRadius()) // 위 
	{
		_dir._y *= -1;
	}

	if (_ball->_center._y >= WIN_HEIGHT - _ball->GetRadius()) // 아래
	{
		_isActive == false;
	}

	if (_ball->GetCenter()._x <= 400 + _ball->GetRadius()) // 왼쪽 
	{
		_dir._x *= -1;
	}

	if (_ball->GetCenter()._x >= 840 - _ball->GetRadius()) // 오른쪽
	{
		_dir._x *= -1;
	}

}

void Ball::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	_ball->Render(hdc);
}

void Ball::Fire(Vector2 dir)
{
	_dir = dir;

}



