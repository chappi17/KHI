#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/SolarSystem.h"
#include "../Scene/GunScene.h"
#include "../Scene/CollisionScene.h"
#include "../Scene/DongScene.h"
#include "../Scene/FortressScene.h"
#include "../Scene/SpriteScene.h"
#include "../Scene/CupHeadScene.h"
#include "../Scene/FilterScene.h"
#include "../Scene/EffectScene.h"

Program::Program()
{
	srand(static_cast<UINT>(time(nullptr)));
	//_scenes["TextureScene"] = make_shared<TextureScene>();
	//_scenes["SolarSystem"] = make_shared<SolarSystem>();
	//_scenes["GunScene"] = make_shared<GunScene>();
	//_scenes["Collision"] = make_shared<CollisionScene>();
	//_scenes["DongScene"] = make_shared<DongScene>();
	//_scenes["FortressScene"] = make_shared<FortressScene>();
	_scenes["SpriteScene"] = make_shared<SpriteScene>();
	_scenes["CupHeadScene"] = make_shared<CupHeadScene>();
	_scenes["FilterScene"] = make_shared<FilterScene>();
	_scenes["EffectScene"] = make_shared<EffectScene>();

	_curscene = _scenes["CupHeadScene"];
}

Program::~Program()
{
}

void Program::Update()
{
	if (KEY_DOWN(VK_F1))
	{
		Collider::_isDebug = !Collider::_isDebug;
	}

	Keyboard::GetInstance()->Update();
	Timer::GetInstance()->Update();
	
	_curscene->Update();

	Camera::Getinstance()->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	// imgui
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Camera::Getinstance()->SetProjectionBuffer(WIN_WIDTH, WIN_HEIGHT); // 투영 정의 
	Camera::Getinstance()->SetCameraWorldBuffer();

	_curscene->PreRender();

	Camera::Getinstance()->SetViewPort();
	AlphaBlendState->SetState();
	
	// Render
	_curscene->Render();

	ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());
	Camera::Getinstance()->PostRender();
	_curscene->PostRender();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}