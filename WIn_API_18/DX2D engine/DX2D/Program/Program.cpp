#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/SolarSystem.h"
#include "../Scene/GunScene.h"
#include "../Scene/CollisionScene.h"

Program::Program()
{
	_scenes["TextureScene"] = make_shared<TextureScene>();
	_scenes["SolarSystem"] = make_shared<SolarSystem>();
	_scenes["GunScene"] = make_shared<GunScene>();
	_scenes["Collision"] = make_shared<CollisionScene>();

	_curscene = _scenes["GunScene"];

	_viewBuffer = make_shared<MatrixBuffer>();
	_projectBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0.0f, WIN_WIDTH, 0, WIN_HEIGHT, -1.0f, 1.0f);

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

	// imgui
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();


	AlphaBlendState->SetState();
	
	_viewBuffer->SetVSBuffer(1);
	_projectBuffer->SetVSBuffer(2);
	
	// Render
	_curscene->Render();

	ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
