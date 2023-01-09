#include "framework.h"
#include "Cup_bullet.h"

Cup_bullet::Cup_bullet()
{	
	CreateAction();

	_collider = make_shared<CircleCollider>(15);
	_collider->GetTransform()->SetParent(_sprite->GetTransform());
	_collider->GetTransform()->Getpos().y += 35;

	_sprite->GetTransform()->GetAngle() = -PI * 0.5f;
	SOUND->Add("Hit", "Resource/Sound/Hit_Sound.wav");
}

Cup_bullet::~Cup_bullet()
{
}

void Cup_bullet::CreateAction()
{
	wstring srvPath;
	srvPath = L"CupHead/Bullet/Special_Bullet_Loop.png";
	shared_ptr<SRV> srv = SRVManager::GetInstance()->AddSRV(srvPath);
	vector<Action::Clip> clips;

	shared_ptr<tinyxml2::XMLDocument> document = make_shared<tinyxml2::XMLDocument>();
	string xmlPath = "Resource/Texture/CupHead/Bullet/Special_Bullet_Loop.xml";
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

	averageW /= count * 4.0f;
	averageH /= count * 4.0f;

	_sprite = make_shared<Sprite>(srvPath, Vector2(averageW, averageH));	

	_action = make_shared<Action>(clips, "Bullet", Action::LOOP, 0.1f);
	_action->Play();
}

void Cup_bullet::Update()
{
	if (isActive == false)
	{	
		_lastTime = RUN_TIME;
		return;
	}
	else
	{
		_curTime = RUN_TIME;
	}

	if (_curTime - _lastTime > _delay)
	{
		_lastTime = 0.0;
		_curTime = 0.0;
		isActive = false;
	}
	
	_sprite->GetTransform()->Getpos() += _direction * _speed * DELTA_TIME;
	_collider->Update();

	_action->Update();
	_sprite->Update();
}

void Cup_bullet::Render()
{
	if (!isActive) return;

	_sprite->SetSpriteByAction(_action->GetCurClip());
	_sprite->Render();
	_collider->Render();
}

void Cup_bullet::Init()
{
	isActive = false;
}

bool Cup_bullet::IsCollisionWithBoss(shared_ptr<Cup_boss> boss)
{	
	if (isActive == false || boss->isActive == false) 
		return false;

	if (_collider->IsCollision(boss->GetCollider()))
	{
		SOUND->Play("Hit");
		isActive == false;
	}

	return _collider->IsCollision(boss->GetCollider());
}

void Cup_bullet::SetDirection(Vector2 dir)
{
	float angle = dir.Angle();
	_direction = dir;
	_sprite->GetTransform()->GetAngle() = angle - PI * 0.5f;
}


