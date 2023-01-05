#include "framework.h"
#include "Cup_player.h"

Cup_player::Cup_player()
{
	_transform = make_shared<Transform>();
	_firepos = make_shared<Transform>();
	_firepos->SetParent(_transform);
	_firepos->Getpos().x += 50;
	_collider = make_shared<CircleCollider>(35);
	_collider->GetTransform()->SetParent(_transform);

	CreateAction("Idle");
	CreateAction("Run");
	CreateAction("Shot");

	_actions[State::IDLE]->SetSpeed(0.1f);
	_actions[State::RUN]->SetSpeed(0.1f);
	_actions[State::SHOT]->SetRepeatType(Action::Type::END);
	_actions[State::SHOT]->SetEndEvent(std::bind(&Cup_player :: SetIdle, this));

	_transform->Getpos() = { CENTER_X, CENTER_Y-150 };

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Cup_bullet> bullet = make_shared<Cup_bullet>();
		_bullets.push_back(bullet);
	}
}

Cup_player::~Cup_player()
{
}

void Cup_player::Input()
{	
	if (_state == State::SHOT)
		return;

	_state = State::IDLE;


	if (KEY_PRESS('A'))
	{
		_transform->Getpos().x -= DELTA_TIME * _speed;
		SetLeft();
		_state = State::RUN;
	}
	if ((KEY_PRESS('D')))
	{
		_transform->Getpos().x += DELTA_TIME * _speed;
		SetRight();	
		_state = State::RUN;
	}
}

void Cup_player::Update()
{
	Shot();
	Input();

	_transform->Update();
	_firepos->Update();
	_collider->Update();
	_actions[_state]->Update();
	_sprites[_state]->Update();	

	for (auto bullet : _bullets)
		bullet->Update();
}

void Cup_player::Render()
{
	_collider->Render();	
	_sprites[_state]->SetSpriteByAction(_actions[_state]->GetCurClip());
	_sprites[_state]->Render();

	for (auto bullet : _bullets)
		bullet->Render();
}

void Cup_player::PostRender()
{
	ImGui::SliderInt("State", (int*)&_state, 0, 1);
}

void Cup_player::CreateAction(string state)
{
	wstring srvPath;
	srvPath.assign(state.begin(), state.end());
	srvPath = L"CupHead/Player/" + srvPath + L".png";
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(srvPath);
	vector<Action::Clip> clips;

	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string xmlPath = "Resource/Texture/CupHead/Player/" + state + ".xml";
	document->LoadFile(xmlPath.c_str());

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
	_firepos->Getpos().x = -30;
	for (auto sprite : _sprites)
	{
		sprite->SetLeft();
	}
}

void Cup_player::SetRight()
{
	_firepos->Getpos().x = +30;
	for (auto sprite : _sprites)
	{
		sprite->SetRight();
	}
}

void Cup_player::Shot()
{
	if (KEY_DOWN(VK_SPACE))
	{
		_state = State::SHOT;
		_actions[_state]->Play();

		auto iter = std::find_if(_bullets.begin(), _bullets.end(), [](const shared_ptr<Cup_bullet>& bullet)->bool
		{
			if (bullet->isActive == false)
				return true;
			return false;
		});

		if (iter != _bullets.end())
		{
			(*iter)->isActive = true;
			(*iter)->SetDirection(_firepos->Getpos().Normal());
			(*iter)->GetTransform()->Getpos() = _firepos->GetWorldPos();
			(*iter)->GetTransform()->Update();			
		}
		
	}
}

void Cup_player::SetIdle()
{
	_state = State::IDLE;
}
