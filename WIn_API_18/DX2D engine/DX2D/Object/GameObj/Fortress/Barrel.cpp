#include "framework.h"
#include "Barrel.h"

Barrel::Barrel()
{
	_quad = make_shared<Quad>(L"Barrel.png", Vector2(100, 30));

	_muzzle = make_shared<Transform>();
	_muzzle->SetParent(_quad->GetTransform());
	_muzzle->Getpos().x += 50;

	_rectCol = make_shared<RectCollider>(Vector2(100, 30));
	_rectCol->GetTransform()->SetParent(_quad->GetTransform());


	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<F_bullet> bullet = make_shared<F_bullet>();
		bullet->_isActive = false;
		_bullets.push_back(bullet);
	}
}

Barrel::~Barrel()
{
}

void Barrel::Update()
{
//	MoveAngle();
	_muzzle->Update();
	_quad->Update();
	_rectCol->Update();

	for (auto bullet : _bullets)
		bullet->Update();
}

void Barrel::Render()
{	
	_muzzle->SetWorldBuffer();
	_quad->Render();
	_rectCol->Render();
	for (auto bullet : _bullets)
		bullet->Render();
}

void Barrel::FireBullet()
{
	Vector2 dir = _muzzle->GetWorldPos() - _quad->GetTransform()->GetWorldPos();

	auto iter = std::find_if(_bullets.begin(), _bullets.end(), [](const shared_ptr<F_bullet>& bullet)->bool
		{
			if (bullet->_isActive == false)
				return true;
			return false;
		});

	if (iter != _bullets.end())
	{
		(*iter)->_isActive = true;
		(*iter)->GetTransform()->Getpos() = _muzzle->GetWorldPos();
		(*iter)->SetDir(dir);
		(*iter)->GetTransform()->GetAngle() = dir.Angle();
	}
	else
	{
	}
}

void Barrel::MoveAngle()
{

	if (KEY_PRESS('W'))
	{
		_quad->GetTransform()->GetAngle() += 0.5f * DELTA_TIME;
	}

	if (KEY_PRESS('S'))
	{
		_quad->GetTransform()->GetAngle() -= 0.5f * DELTA_TIME;
	}

}