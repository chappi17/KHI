#include "framework.h"
#include "Fortress_scene.h"

Fortress_scene::Fortress_scene()
{
	_cannon = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();
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
		_angle -= 0.01f;
	if (GetAsyncKeyState(VK_DOWN))
		_cannon->MoveDown();
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
		_cannon->Fire();

	_cannon->SetAngle(_angle);

	for (auto bullet : _cannon->GetBullests())
	{
		if (_cannon2->IsCollision(bullet))
		{
			_cannon2->_isActive = false;
			bullet->SetActive(false);
		}
	}
}

void Fortress_scene::Render(HDC hdc)
{
	_cannon->Render(hdc);
	_cannon2->Render(hdc);
}
