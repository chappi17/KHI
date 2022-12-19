#include "framework.h"
#include "GunScene.h"

GunScene::GunScene()
{
	_player = make_shared<Player>();
	_player->Move({ CENTER_X,CENTER_Y });	
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

	_player->Update();
}

void GunScene::Render()
{
	_player->Render();

	ImGui::SliderFloat("PosX", &_player->GetTransform()->Getpos()._x, 0, WIN_WIDTH);
	ImGui::SliderFloat("PosY", &_player->GetTransform()->Getpos()._y, 0, WIN_HEIGHT);
}
