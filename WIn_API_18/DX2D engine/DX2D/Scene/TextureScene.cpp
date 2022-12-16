#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_texture1 = make_shared<Quad>(L"2B.png" );
	_texture2 = make_shared<Quad>(L"BM.png", Vector2(150,150));

	_texture2->SetParent(_texture1->GetTransform());

	_worldBuffer = make_shared<MatrixBuffer>();
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicLH(WIN_WIDTH, WIN_HEIGHT, 0.0f, 1.0f);

	_projectBuffer->SetData(projectionM);
	_worldBuffer->Update();
	_viewBuffer->Update();
	_projectBuffer->Update();
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
	XMMATRIX viewS = XMMatrixScaling(1, 1, 1);
	XMMATRIX viewR = XMMatrixRotationZ(_cameraAngle);
	XMMATRIX viewT = XMMatrixTranslation(_cameraPos.x, _cameraPos.y, 0);
	XMMATRIX viewSRT = viewS * viewR * viewT;
	_viewBuffer->SetData(viewSRT);
	_viewBuffer->Update();

	_texture1->GetTransform()->GetAngle() += 0.001f;
	_texture1->GetTransform()->Getpos()._x = 100;

	_texture1->Update();
	_texture2->Update();
}

void TextureScene::Render()
{	
	_worldBuffer->SetVSBuffer(0);
	_viewBuffer->SetVSBuffer(1);
	_projectBuffer->SetVSBuffer(2);

	_texture1->Render();
	_texture2->Render();
}
