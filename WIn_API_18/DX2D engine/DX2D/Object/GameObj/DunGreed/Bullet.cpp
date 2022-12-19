#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_quad = make_shared<Quad>(L"Bullet.png", Vector2(150, 150));
}

Bullet::~Bullet()
{
}

void Bullet::Update()
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

	_quad->GetTransform()->Getpos() += _dir * _speed * DELTA_TIME;
}

void Bullet::Render()
{
	if (_isActive == false)
		return;

	_quad->Render();
}
