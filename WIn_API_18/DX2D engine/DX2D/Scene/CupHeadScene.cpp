#include "framework.h"
#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	
	_player = make_shared<Cup_player>();
	_bg = make_shared<Cup_Background>();
	_boss = make_shared<Cup_boss>();
	_boss->isActive = true;

	_effect = make_shared<Effect>
		(L"Effects/explosion.png", Vector2(5, 3), Vector2(100, 100));	
	_effect->isActive = true;
	EFFECT->AddEffect(L"Effects/explosion.png", Vector2(5, 3), Vector2(100, 100));


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
	//if (KEY_DOWN(VK_SPACE))
	//{
	//	Camera::Getinstance()->ShakeStart(3.0f, 0.3f);
	//}

	for (auto bullet : _player->GetBullets())
	{
		if (bullet->IsCollisionWithBoss(_boss))
		{	
			Camera::Getinstance()->ShakeStart(3.0f, 0.3f);
			_effect->Play(bullet->GetCollider()->GetTransform()->GetWorldPos());
			--_boss->GetHp();
			bullet->Init();
			break;
		}
	}

	if (_boss->GetHp() <= 0)
	{
 		_boss->isActive = false;
	}
	_effect->Update();
	_player->Update();
	_boss->Update();
}

void CupHeadScene::PreRender()
{
	_bg->Render();
}

void CupHeadScene::Render()
{	
	_effect->Render();
	_player->Render();
	_boss->Render();
}

void CupHeadScene::PostRender()
{
	int bossHp = _boss->GetHp();
	ImGui::SliderInt("BossHp", &bossHp, 0, 10);
}
