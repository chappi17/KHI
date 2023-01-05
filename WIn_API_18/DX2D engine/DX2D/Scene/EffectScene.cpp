#include "framework.h"
#include "EffectScene.h"

EffectScene::EffectScene()
{
//	CAMERA->SetTarget(nullptr);

	_effect = make_shared<Effect>
		(L"Effects/explosion.png", Vector2(5, 3), Vector2(100, 100));
	_effect->Play(Vector2({ CENTER_X,CENTER_Y }));
	_effect->isActive = true;

	_bg = make_shared<Cup_Background>();
}

EffectScene::~EffectScene()
{
}

void EffectScene::Update()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		_effect->Play(CAMERA->GetWorldMousePos());
	}
	_effect->Update();
}

void EffectScene::Render()
{
	_effect->Render();
}

void EffectScene::PreRender()
{
	_bg->Render();
}

void EffectScene::PostRender()
{	ImGui::Text("mouseX : %0.1f, mouseY : %0.1f", CAMERA->GetWorldMousePos().x, CAMERA->GetWorldMousePos().y);
}
