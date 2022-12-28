#include "framework.h"
#include "Cup_player.h"

Cup_player::Cup_player()
{
	_sprite = make_shared<Sprite>(L"CupHead/Idle.png",Vector2(5,1),Vector2(150,150));
	_sprite->GetTransform()->Getpos() = { CENTER_X,CENTER_Y };

	_collider = make_shared<CircleCollider>(35);
	_collider->GetTransform()->SetParent(_sprite->GetTransform());
	CreateAction();
}

Cup_player::~Cup_player()
{
}

void Cup_player::Input()
{
	if (KEY_PRESS('A'))
	{
		_sprite->GetTransform()->Getpos().x -= DELTA_TIME * _speed;
		_sprite->SetLeftRight(1);
	}
	if (KEY_PRESS('D'))
	{
		_sprite->GetTransform()->Getpos().x += DELTA_TIME * _speed;
		_sprite->SetLeftRight(0);
	}
}

void Cup_player::Update()
{
	Input();
	_action->Update();
	_collider->Update();
	_sprite->Update();
}

void Cup_player::Render()
{
	_sprite->SetSprite(_action->GetCurClip());
	_sprite->Render();
	_collider->Render();
}

void Cup_player::PostRender()
{
	ImGui::Text(_text.c_str());
}

void Cup_player::CreateAction()
{
	shared_ptr<SRV> srv_1 = SRVManager::GetInstance()->AddSRV(L"Idle.png");
	vector<Action::Clip> clips_1;

	Action::Clip clip0_1 = Action::Clip(1, 1, 300, 300, srv_1);
	clips_1.emplace_back(clip0_1);

	Action::Clip clip1_1 = Action::Clip(303, 1, 300, 300, srv_1);
	clips_1.emplace_back(clip1_1);

	Action::Clip clip_2 = Action::Clip(605, 1, 300, 300, srv_1);
	clips_1.emplace_back(clip_2);

	Action::Clip clip_3 = Action::Clip(907, 1, 300, 300, srv_1);
	clips_1.emplace_back(clip_3);

	Action::Clip clip_4 = Action::Clip(1209, 1, 300, 300, srv_1);
	clips_1.emplace_back(clip_4);

	_action = make_shared<Action>(clips_1, "CupHead_Idle", Action::END, 0.5f);
	_action->Play();

	_action->SetEndEvent(std::bind(&Cup_player::SetText, this));


	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(L"Run.png");
	vector<Action::Clip> clips;

	Action::Clip clip0 = Action::Clip(1, 158, 137, 157, srv);
	clips.emplace_back(clip0);

	Action::Clip clip1 = Action::Clip(127, 640, 124, 151, srv);
	clips.emplace_back(clip1);

	Action::Clip clip2 = Action::Clip(1, 1069, 115, 159, srv);
	clips.emplace_back(clip2);

	Action::Clip clip3 = Action::Clip(142, 1, 111, 164, srv);
	clips.emplace_back(clip3);

	Action::Clip clip4 = Action::Clip(140, 167, 112, 171, srv);
	clips.emplace_back(clip4);

	Action::Clip clip5 = Action::Clip(118, 1095, 114, 146, srv);
	clips.emplace_back(clip5);

	Action::Clip clip6 = Action::Clip(1, 769, 124, 148, srv);
	clips.emplace_back(clip6);

	Action::Clip clip7 = Action::Clip(1, 317, 132, 148, srv);
	clips.emplace_back(clip7);

	Action::Clip clip8 = Action::Clip(1, 615, 124, 152, srv);
	clips.emplace_back(clip8);

	Action::Clip clip9 = Action::Clip(1, 919, 116, 148, srv);
	clips.emplace_back(clip9);

	Action::Clip clip10 = Action::Clip(119, 942, 115, 151, srv);
	clips.emplace_back(clip10);

	Action::Clip clip11 = Action::Clip(135, 340, 117, 152, srv);
	clips.emplace_back(clip11);

	Action::Clip clip12 = Action::Clip(127, 793, 122, 147, srv);
	clips.emplace_back(clip12);

	Action::Clip clip13 = Action::Clip(133, 494, 120, 144, srv);
	clips.emplace_back(clip13);

	Action::Clip clip14 = Action::Clip(1, 467, 130, 146, srv);
	clips.emplace_back(clip14);

	Action::Clip clip15 = Action::Clip(1, 1, 139, 155, srv);
	clips.emplace_back(clip15);

	//_action = make_shared<Action>(clips, "CupHead_Run", Action::LOOP, 0.2f);
	//_action->Play();

	//_action->SetEndEvent(std::bind(&Cup_player::SetText, this));

}
