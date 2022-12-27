#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring file, Vector2 maxFrame)
	:Quad(file)
{
	_frameBuffer = make_shared<FrameBuffer>();
	_frameBuffer-> _data.maxFrame = maxFrame;

	_ps = make_shared<PixelShader>(L"SpritePixelShader");
}

Sprite::Sprite(wstring file, Vector2 maxFrame, Vector2 size)
	:Quad(file,size)
{
	_frameBuffer = make_shared<FrameBuffer>();
	_frameBuffer->_data.maxFrame = maxFrame;

	_ps = make_shared<PixelShader>(L"SpritePixelShader");
}

void Sprite::Update()
{
	_frameBuffer->Update();
	Quad::Update();
}

void Sprite::Render()
{
	_frameBuffer->SetPSBuffer(0);
	Quad::Render();
}

void Sprite::SetSprite(Vector2 curFrame)
{
	_frameBuffer->_data.curFrame = curFrame;
}
