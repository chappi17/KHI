#include "framework.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_quad = make_shared<Quad>(L"Fortress.png", Vector2(100, 100));
	_rotation = make_shared<Transform>();
	_rotation->SetParent(_quad->GetTransform());

	_barrel = make_shared<Barrel>();
	_barrel->GetTransform()->SetParent(_rotation);

	_barrel->GetTransform()->Getpos().x += 50;	

	_circleCol = make_shared<CircleCollider>(60);
	_circleCol->GetTransform()->SetParent(_quad->GetTransform());
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	Move();	
	_rotation->Update();
	_barrel->Update();
	_quad->Update();
	_circleCol->Update();

	
	//_barrel->GetEndPos()._x = _quad->GetTransform()->GetWorldPos()._x * cosf(_angle);
	//_barrel->GetEndPos()._y = _quad->GetTransform()->GetWorldPos()._y * sinf(_angle);

}

void Cannon::Render()
{
	_barrel->Render();
	_quad->Render();
	_circleCol->Render();
}

void Cannon::Set(const Vector2 pos)
{
	_quad->GetTransform()->Getpos()= pos;
}

void Cannon::Fire()
{
	_barrel->FireBullet();
}



void Cannon::Move()
{
	if (KEY_PRESS('A'))
	{
		_quad->GetTransform()->Getpos().x -= _speed * DELTA_TIME;
	}

	if (KEY_PRESS('D'))
	{
		_quad->GetTransform()->Getpos().x += _speed * DELTA_TIME;
	}

	if (KEY_PRESS('W'))
	{
		_rotation->GetAngle() += 0.5f * DELTA_TIME;
	}
	if (KEY_PRESS('S'))
	{
		_rotation->GetAngle() -= 0.5f * DELTA_TIME;
	}
}