#include "framework.h"
#include "Fortress_scene.h"

Fortress_scene::Fortress_scene()
{
	_cannon = make_shared<Cannon>();
}

Fortress_scene::~Fortress_scene()
{
}

void Fortress_scene::Update()
{
	_cannon->Update();

	if (GetAsyncKeyState(VK_LEFT))
		_cannon->MoveLeft();
	if (GetAsyncKeyState(VK_RIGHT))
		_cannon->MoveRight();
	if (GetAsyncKeyState(VK_UP))
		_cannon->GetAngle() -= 0.01f;
	if (GetAsyncKeyState(VK_DOWN))
		_cannon->GetAngle() += 0.01f;
	if (GetAsyncKeyState(VK_SPACE))
		_cannon->Fire();

	//if (_enemy_body->IsCollision(_bullet))
	//	_enemy_body->SetRED();
	

}

void Fortress_scene::Render(HDC hdc)
{
	_cannon->Render(hdc);
}
