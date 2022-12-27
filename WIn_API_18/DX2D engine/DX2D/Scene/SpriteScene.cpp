#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_quad = make_shared<Quad>(L"weather.png", Vector2(50, 50));
	_quad->GetTransform()->Getpos() = { CENTER_X, CENTER_Y };
	_quad->_ps = make_shared<PixelShader>(L"SpritePixelShader");
	_maxFrameBuffer = make_shared<SpriteBuffer>();
	_maxFrameBuffer->_data.maxFrame = { 6,5 };
	_maxFrameBuffer->_data.curFrame = { 1,0 };
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_quad->Update();
}

void SpriteScene::Render()
{
	AdditiveBlendState->SetState();
	_maxFrameBuffer->SetPSBuffer(0);
	_quad->Render();
}

void SpriteScene::PostRender()
{
	ImGui::SliderFloat("FrameX", &_maxFrameBuffer->_data.curFrame.x, 0, 5);
	ImGui::SliderFloat("FrameY", &_maxFrameBuffer->_data.curFrame.y, 0, 4);
}
