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
	if (KEY_DOWN(VK_LBUTTON))
	{
		_player->Fire(mousePos);
	}

	_player->Update();

}

void GunScene::Render()
{
	_player->Render();
}
