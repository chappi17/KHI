#include "framework.h"
#include "Dong.h"

Dong::Dong()
{
	_quad = make_shared<Quad>(L"Mococo.png", Vector2(50, 50));
	_quad->GetTransform()->Getpos() = Vector2(CENTER_X, CENTER_Y);

	_circleCol = make_shared<CircleCollider>(40);
	_circleCol->GetTransform()->SetParent(_quad->GetTransform());

}

Dong::~Dong()
{
}

void Dong::Update()
{
	if (_isActive == false)
		return;

	if (_quad->GetTransform()->Getpos()._y < 0)
	{
		Init();
		return;
	}
	_quad->GetTransform()->Getpos()._y -= _speed * DELTA_TIME;

	_quad->Update();
	_circleCol->Update();
}

void Dong::Render()
{
	if (_isActive == false)
		return;

	_quad->Render();
	_circleCol->Render();	
}

void Dong::Init()
{
	_quad->GetTransform()->Getpos()._y = WIN_HEIGHT + 50;
	_quad->GetTransform()->Getpos()._x = rand() % WIN_WIDTH;
	_quad->GetTransform()->Update();
	_isActive = false;
}

bool Dong::IsCollisionWithPlayer(shared_ptr<D_Player> player)
{
	if (_isActive == false || player->_isActive == false)
		return false;

	return _circleCol->IsCollision(player->GetCollider());
}


