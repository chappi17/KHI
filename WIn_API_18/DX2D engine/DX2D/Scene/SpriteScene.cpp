#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_sprite = make_shared<Sprite>(L"X_man.png", Vector2(5,2), Vector2(100,100));
	_sprite->GetTransform()->Getpos() = { CENTER_X, CENTER_Y };

	CreateAction();
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_sprite->Update();
	_action->Update();
}

void SpriteScene::Render()
{
	AdditiveBlendState->SetState();		
	_sprite->Render();
	_sprite->SetSprite(_action->GetCurClip());
}

void SpriteScene::PostRender()
{
	ImGui::SliderInt("FrameX", &_frameX, 0, 4);
	ImGui::SliderInt("FrameY", &_frameY, 0, 1);
	ImGui::SliderInt("LeftRight", &_leftRight, 0, 1);
	_sprite->SetLeftRight(_leftRight);

	ImGui::SliderInt("CHECK", &_check, 0, 100);
}

void SpriteScene::CreateAction()
{
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(L"X_man.png");
	vector<Action::Clip> clips;
	Vector2 imageSize = srv->GetSize();
	Vector2 maxFrame = { 5,2 };
	float w = imageSize.x / maxFrame.x;
	float h = imageSize.y / maxFrame.y;


	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			Action::Clip clip1 = Action::Clip(x * w, y * h, w, h, srv);
			clips.emplace_back(clip1);
		}
	}

	 _action = make_shared<Action>(clips, "XMAN_RUN",Action::END);
	 _action->Play();
	 
	// _action->SetEndEvent(std::bind(&SpriteScene::Check, this));
	 _action->SetTestEvent(std::bind(&SpriteScene::Check_1, this, 10));
	}

void SpriteScene::Check()
{
	_check = 50;
}

void SpriteScene::Check_1(int t)
{
	_check = t;
}
