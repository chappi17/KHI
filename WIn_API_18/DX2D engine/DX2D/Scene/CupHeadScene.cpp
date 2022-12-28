#include "framework.h"
#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<Cup_player>();
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_player->Update();
}

void CupHeadScene::Render()
{
	_player->Render();
}

void CupHeadScene::PostRender()
{
	_player->PostRender();
}
