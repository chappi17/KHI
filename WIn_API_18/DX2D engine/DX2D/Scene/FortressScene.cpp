#include "framework.h"
#include "FortressScene.h"

FortressScene::FortressScene()
{
	_player = make_shared<Cannon>();
	_player->Set({ CENTER_X,CENTER_Y });
	
}

FortressScene::~FortressScene()
{
}

void FortressScene::Update()
{

	if (KEY_DOWN(VK_SPACE))
	{
		_player->Fire();
	}
	_player->Update();

}

void FortressScene::Render()
{
	_player->Render();
}