#include "framework.h"
#include "Bar.h"

Bar::Bar()
{
	_bar = make_shared<RectCollider>(Vector2(CENTER_X, 600), Vector2(100, 20));	
}

Bar::~Bar()
{
}

void Bar::Update()
{
	_bar->Update();
}

void Bar::Render(HDC hdc)
{
	_bar->Render(hdc);
}

void Bar::MoveLeft()
{
	Vector2 temp = _bar->GetCenter();
	temp._x -= _speed;
	_bar->SetCenter(temp);
}

void Bar::MoveRight()
{
	Vector2 temp = _bar->GetCenter();
	temp._x += _speed;
	_bar->SetCenter(temp);
}

void Bar::Fire(Vector2 vector)
{	

	
}
