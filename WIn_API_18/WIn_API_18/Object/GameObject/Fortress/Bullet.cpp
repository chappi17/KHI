#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_ball = make_shared<CircleCollider>(Vector2{ -1,-1 }, 5);
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_isActive == false)
		return;

	_ball->Update();

	_gravity._y += GRAVITY;

	Vector2 now = _ball->GetCenter();
	now += _dir.Normallize() * _speed;
	//now += _gravity;
	_ball->SetCenter(now);

	if (_ball->GetCenter()._x > WIN_WIDTH || _ball->GetCenter()._x <0
		|| _ball->GetCenter()._y > WIN_HEIGHT || _ball->GetCenter()._y < 0)
	{
		_gravity._y = 0.0f;
		_isActive = false;
	}
	

	if (_ball->GetCenter()._y > WIN_HEIGHT || _ball->GetCenter()._y < 0)
	{
		_dir._y *= -1.0f;
	}

	if (_ball->GetCenter()._x > WIN_WIDTH || _ball->GetCenter()._x < 0)
	{
		_dir._x *= -1.0f;
	}
}

void Bullet::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	_ball->Render(hdc);
}

void Bullet::Fire(Vector2 dir)
{
	_dir = dir;
}

void Bullet::SetPos(Vector2 pos)
{
	_ball->SetCenter(pos);
}

