#include "framework.h"
#include "CupHeadScene.h"

CupHeadScene::CupHeadScene()
{
	_sprite = make_shared<Sprite>(L"Idle.png", Vector2(5, 1), Vector2(300, 300));
	_sprite->GetTransform()->Getpos() = { CENTER_X, CENTER_Y };

	CreateAction();
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_sprite->Update();
	_action->Update();
}

void CupHeadScene::Render()
{
	AdditiveBlendState->SetState();
	_sprite->Render();
	_sprite->SetSprite(_action->GetCurClip());
}

void CupHeadScene::PostRender()
{
	ImGui::SliderInt("FrameX", &_frameX, 0, 4);
	ImGui::SliderInt("FrameY", &_frameY, 0, 1);
	ImGui::SliderInt("LeftRight", &_leftRight, 0, 1);
	_sprite->SetLeftRight(_leftRight);
}

void CupHeadScene::CreateAction()
{
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(L"Idle.png");
	vector<Action::Clip> clips;
	Vector2 imageSize = srv->GetSize();
	Vector2 maxFrame = { 5,1 };
	float w = imageSize.x / maxFrame.x;
	float h = imageSize.y / maxFrame.y;

	Action::Clip clip0 = Action::Clip(1, 1 , 300, 300, srv);
	clips.emplace_back(clip0);

	Action::Clip clip1 = Action::Clip(303, 1, 300, 300, srv);
	clips.emplace_back(clip1);

	Action::Clip clip2 = Action::Clip(605, 1, 300, 300, srv);
	clips.emplace_back(clip2);

	Action::Clip clip3 = Action::Clip(907, 1, 300, 300, srv);
	clips.emplace_back(clip3);

	Action::Clip clip4 = Action::Clip(1209, 1, 300, 300, srv);
	clips.emplace_back(clip4);

	_action = make_shared<Action>(clips, "CupHead_Idle", Action::LOOP);
	_action->Play();
}
