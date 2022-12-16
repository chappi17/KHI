#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/SolarSystem.h"
#include "../Scene/GunScene.h"

Program::Program()
{
	_scenes["GunScene"] = make_shared<GunScene>();
	_curscene = _scenes["GunScene"];

	_viewBuffer = make_shared<MatrixBuffer>();
	_projectBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicLH(WIN_WIDTH, WIN_HEIGHT, 0.0f, 1.0f);

	_projectBuffer->SetData(projectionM);

	_viewBuffer->Update();
	_projectBuffer->Update();

}

Program::~Program()
{
}

void Program::Update()
{
	Keyboard::GetInstance()->Update();
	Timer::GetInstance()->Update();
	_curscene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();
	AlphaBlendState->SetState();
	
	_viewBuffer->SetVSBuffer(1);
	_projectBuffer->SetVSBuffer(2);
	
	// Render
	_curscene->Render();

	Device::GetInstance()->Present();
}
