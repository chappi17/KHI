#include "framework.h"
#include "Cup_bullet.h"

Cup_bullet::Cup_bullet()
{

	_transform = make_shared<Transform>();
	_transform->Getpos() = { CENTER_X,CENTER_Y-150 };

	_circleCol = make_shared<CircleCollider>(5);
	_circleCol->GetTransform()->SetParent(_transform);
}

Cup_bullet::~Cup_bullet()
{
}

void Cup_bullet::Update()
{
	if (_isActive == false)
		return;

	_transform->Update();	
	_circleCol->Update();
	_transform->Getpos().x += _speed * DELTA_TIME;
}

void Cup_bullet::Render()
{
	if (_isActive == false)
		return;

	_transform->SetWorldBuffer();
	_circleCol->Render();
}


