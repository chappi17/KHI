#include "framework.h"
#include "GunScene.h"

GunScene::GunScene()
{
	_player = make_shared<Player>();
	_player->Move({ CENTER_X,CENTER_Y });

	_target = make_shared<RectCollider>(Vector2(50, 50));
	_target->GetTransform()->Getpos() = { CENTER_X + 300 ,CENTER_Y };
}

GunScene::~GunScene()
{
}

void GunScene::Update()
{	
	if (KEY_DOWN(VK_LBUTTON) && !ImGui::GetIO().WantCaptureMouse)
	{
		_player->Fire(mousePos);
	}

	for (auto bullet : _player->GetGun()->GetBullets())
	{
		if (bullet->IsCollision(_target))
		{
			_target->SetRED();
			break;
		}
		else
		{
			_target->SetGREEN();
		}
	}

	_player->Update();
	_target->Update();
}

void GunScene::Render()
{
	_player->Render();
	_target->Render();

	ImGui::SliderFloat("PosX", &_player->GetTransform()->Getpos().x, 0, WIN_WIDTH);
	ImGui::SliderFloat("PosY", &_player->GetTransform()->Getpos().y, 0, WIN_HEIGHT);
}