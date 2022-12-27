#include "framework.h"
#include "D_BackGround.h"

D_BackGround::D_BackGround()
{
	_quad = make_shared<Quad>(L"2B.png");
	_quad->GetTransform()->Getpos() = { CENTER_X,CENTER_Y };
}

D_BackGround::~D_BackGround()
{
}

Vector2 D_BackGround::LeftRight()
{
	Vector2 result;
	result.x =_quad->GetTransform()->Getpos().x - _quad->GetSize().x * 0.5f;
	result.y =_quad->GetTransform()->Getpos().x + _quad->GetSize().x * 0.5f;

	return result;
}

void D_BackGround::Update() 
{
	_quad->Update();
}

void D_BackGround::Render()
{
	_quad->Render();
}
