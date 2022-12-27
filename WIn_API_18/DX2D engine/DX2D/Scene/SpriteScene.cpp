#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_sprite = make_shared<Sprite>(L"X_man.png", Vector2(5,2), Vector2(100,100));
	_sprite->GetTransform()->Getpos() = { CENTER_X, CENTER_Y };
	_leftRightBuffer = make_shared<LeftRightBuffer>();
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_sprite->Update();
	_sprite->SetSprite(Vector2(_frameX, _frameY));
}

void SpriteScene::Render()
{
	AdditiveBlendState->SetState();	
	_leftRightBuffer->SetPSBuffer(0);
	_sprite->Render();
}

void SpriteScene::PostRender()
{
	ImGui::SliderInt("FrameX", &_frameX, 0, 4);
	ImGui::SliderInt("FrameY", &_frameY, 0, 1);
	ImGui::SliderInt("LeftRight", &_leftRightBuffer->_data.leftRight, 0, 1);
}
