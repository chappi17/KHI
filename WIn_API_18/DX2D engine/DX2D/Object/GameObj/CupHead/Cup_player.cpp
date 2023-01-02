#include "framework.h"
#include "Cup_player.h"

Cup_player::Cup_player()
{
	_transform = make_shared<Transform>();
	_collider = make_shared<CircleCollider>(35);
	_collider->GetTransform()->SetParent(_transform);
	CreateAction("Idle");
	CreateAction("Run");
	CreateAction("Shot");


	_actions[State::IDLE]->SetSpeed(0.1f);
//	_actions[State::RUN]->SetSpeed(0.7f);

	_transform->Getpos() = { CENTER_X, CENTER_Y-150 };
}

Cup_player::~Cup_player()
{
}

void Cup_player::Input()
{	
	shared_ptr<Sprite> sprite;
	if (KEY_PRESS('A'))
	{
		_transform->Getpos().x -= DELTA_TIME * _speed;
		_state = State::RUN;
		SetLeft();
		
	}
	else if ((KEY_PRESS('D')))
	{
		_transform->Getpos().x += DELTA_TIME * _speed;
		_state = State::RUN;
		SetRight();
	
	}

	else if ((KEY_PRESS('F')))
	{		
		_state = State::SHOT;
	}
	else
		_state = State::IDLE;	
}

void Cup_player::Update()
{
	Input();

	_transform->Update();
	_collider->Update();
	_actions[_state]->Update();
	_sprites[_state]->Update();
}

void Cup_player::Render()
{
	_transform->SetWorldBuffer();
	_sprites[_state]->SetSpriteByAction(_actions[_state]->GetCurClip());
	_sprites[_state]->Render();	
	_collider->Render();
}

void Cup_player::PostRender()
{
	ImGui::SliderInt("State", (int*)&_state, 0, 1);
}

void Cup_player::CreateAction(string state)
{
	wstring srvPath;
	srvPath.assign(state.begin(), state.end());
	srvPath = L"CupHead/" + srvPath + L".png";
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(srvPath);
	vector<Action::Clip> clips;


	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string xmlpath = "Resource/Texture/CupHead/" + state + ".xml";
	document->LoadFile(xmlpath.c_str());

	tinyxml2::XMLElement* TextureAtlas = document->FirstChildElement();
	tinyxml2::XMLElement* row = TextureAtlas->FirstChildElement();

	int averageW = 0;
	int averageH = 0;
	int count = 0;


	while (true)
	{
		if (row == nullptr)
			break;
		int x = row->FindAttribute("x")->IntValue();
		int y = row->FindAttribute("y")->IntValue();
		int w = row->FindAttribute("w")->IntValue();
		averageW += w;
		int h = row->FindAttribute("h")->IntValue();
		averageH += h;

		count++;

		Action::Clip clip = Action::Clip(x, y, w, h, srv);
		clips.push_back(clip);

		row = row->NextSiblingElement();
	}

	shared_ptr<Sprite> sprite;

	averageW /= count * 1.5f;
	averageH /= count * 1.5f;

	sprite = make_shared<Sprite>(srvPath, Vector2(averageW, averageH));

	sprite->GetTransform()->SetParent(_transform);
	_sprites.push_back(sprite);

	shared_ptr<Action> action = make_shared<Action>(clips, state, Action::LOOP, 0.1f);
	action->Play();
	_actions.push_back(action);
}

void Cup_player::SetLeft()
{
	for (auto sprite : _sprites)
	{
		sprite->SetLeft();
	}
}

void Cup_player::SetRight()
{
	for (auto sprite : _sprites)
	{
		sprite->SetRight();
	}
}
