#include "framework.h"
#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	
	_player = make_shared<Cup_player>();
	_bg = make_shared<Cup_Background>();
	_boss = make_shared<Cup_boss>();

	

	Camera::Getinstance()->SetTarget(_player->GetTransform());
	Camera::Getinstance()->SetOffSet({ CENTER_X, 160 });
	Camera::Getinstance()->SetLeftBottom(_bg->GetSize() * 0.5f * -1.0f + _bg->GetMainPos());
	Camera::Getinstance()->SetRightTop(_bg->GetSize() * 0.5f + _bg->GetMainPos());
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	if (KEY_DOWN(VK_SPACE))
	{
		Camera::Getinstance()->ShakeStart(3.0f, 0.3f);
	}
//	_bg->Update();
	
	_player->Update();
	_boss->Update();
}

void CupHeadScene::PreRender()
{
	_bg->Render();
}

void CupHeadScene::Render()
{	

	_player->Render();
	_boss->Render();
}

void CupHeadScene::PostRender()
{
	_player->PostRender();
}
