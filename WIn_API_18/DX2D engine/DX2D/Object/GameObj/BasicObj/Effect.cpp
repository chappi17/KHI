#include "framework.h"
#include "Effect.h"

Effect::Effect(wstring file, Vector2 maxFrame, Vector2 size, float speed , Action::Type type)
{
	_sprite = make_shared<Sprite>(file, maxFrame, size);
	CreateAction(file, maxFrame, speed, type);
	_action->SetEndEvent(std::bind(&Effect::End, this));
}

Effect::~Effect()
{
}

void Effect::Update()
{
	if (isActive == false)
		return;
	_sprite->Update();
	_action->Update();
	_sprite->SetSpriteByAction(_action->GetCurClip());
}

void Effect::Render()
{
	if (isActive == false)
		return;

	_sprite->Render();
}

void Effect::PostRender()
{
}

void Effect::CreateAction(wstring file, Vector2 maxFrame, float speed , Action::Type type)
{
	vector<Action::Clip> clips;

	float w = _sprite->GetImage().x / maxFrame.x;
	float h = _sprite->GetImage().y / maxFrame.y;
	

	for (int y = 0; y < maxFrame.y; y++)
	{
		for (int x = 0; x < maxFrame.x; x++)
		{
			Action::Clip clip = Action::Clip(x * w, y * h, w, h, SRVManager::GetInstance()->AddSRV(file));
			clips.push_back(clip);
		}
	}

	string effectName(file.begin(), file.end());
	effectName = effectName.substr(effectName.find_last_of("/")+1, effectName.size());
	effectName = effectName.substr(0, effectName.find_last_of("."));

	_action = make_shared<Action>(clips, effectName, type, speed);
}

void Effect::Play(Vector2 pos)
{
	isActive = true;
	_sprite->GetTransform()->Getpos() = pos;
	_action->Play();
}

void Effect::End()
{
	isActive = false;
}
