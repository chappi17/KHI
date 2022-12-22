#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_quad = make_shared<Quad>(L"Bullet.png", Vector2(130, 130));

	_circleCol = make_shared<CircleCollider>(5);
	_circleCol->GetTransform()->Getpos()._x += 30;
	_circleCol->GetTransform()->SetParent(_quad->GetTransform());
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

	_circleCol->Update();
}

void Bullet::Render()
{
	if (_isActive == false)
		return;

	_quad->Render();
	_circleCol->Render();
}

bool Bullet::IsCollision(shared_ptr<RectCollider> rect)
{
	return _circleCol->IsCollision(rect);
}

bool Bullet::IsCollision(shared_ptr<class Player> player)
{
	return _circleCol->IsCollision(player->GetCollider());
}
