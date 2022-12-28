#include "framework.h"
#include "F_bullet.h"

F_bullet::F_bullet()
{
	_quad = make_shared<Quad>(L"Cannonball.png", Vector2(100, 100));

	_circleCol = make_shared<CircleCollider>(30);
	_circleCol->GetTransform()->SetParent(_quad->GetTransform());
}

F_bullet::~F_bullet()
{
}

void F_bullet::Update()
{
	if (_isActive == false)
	{
		_lastTime = RUN_TIME;
		return;
	}
	else
	{
		_curTime = RUN_TIME;
	}

	if (_curTime - _lastTime > _delay)
	{
		_lastTime = 0.0;
		_curTime = 0.0;
		_isActive = false;
	}
	_quad->Update();
	_circleCol->Update();

	_quad->GetTransform()->Getpos() += _dir * _speed * DELTA_TIME;
	_quad->GetTransform()->GetAngle() += _speed * DELTA_TIME;
}

void F_bullet::Render()
{
	if (_isActive == false)
		return;
	_quad->Render();
	_circleCol->Render();
}

void F_bullet::Fire(Vector2 dir)
{
	_dir = dir;
}