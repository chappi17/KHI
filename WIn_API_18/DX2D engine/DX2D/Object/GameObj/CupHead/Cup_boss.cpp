#include "framework.h"
#include "Cup_boss.h"

Cup_boss::Cup_boss()
{
	_transform = make_shared<Transform>();
	_collider = make_shared<RectCollider>(Vector2(380, 520));
	_collider->GetTransform()->Getpos().x -= 25;
	_collider->GetTransform()->SetParent(_transform);

	CreateAction("Page_Two_Intro_2");

	_transform->Getpos() = { CENTER_X + 450, CENTER_Y+50};
	
}

Cup_boss::~Cup_boss()
{
}

void Cup_boss::SetIdle()
{
}

void Cup_boss::Update()
{
	if (isActive == false && _hp <= 0)
		return;

	_transform->Update();
	_collider->Update();
	_actions[_state]->Update();
	_sprites[_state]->Update();
}

void Cup_boss::Render()
{
	if (!isActive) return;

	_collider->Render();
	_sprites[_state]->SetSpriteByAction(_actions[_state]->GetCurClip());
	_sprites[_state]->Render();
}

void Cup_boss::PostRender()
{
}

void Cup_boss::CreateAction(string state)
{
	wstring srvPath;
	srvPath.assign(state.begin(), state.end());
	srvPath = L"CupHead/Boss/" + srvPath + L".png";
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(srvPath);
	vector<Action::Clip> clips;

	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string xmlPath = "Resource/Texture/CupHead/Boss/" + state + ".xml";
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
