#include "framework.h"
#include "EffectManager.h"

EffectManager* EffectManager::_instance = nullptr;

EffectManager::EffectManager()
{
}

EffectManager::~EffectManager()
{
}

void EffectManager::AddEffect(wstring path, Vector2 maxFrame, Vector2 size, float speed, Action::Type type)
{
	string temp = string(path.begin(), path.end());
	temp = temp.substr(temp.find_last_of("/")+1, temp.npos);
	temp = temp.substr(0, temp.find_last_of("."));

	if (_effectTable.count(temp) != 0)
	{
		return;
	}	

	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Effect> effect = make_shared<Effect>(path, maxFrame, size, speed, type);
		effect->isActive = false;
		_effectTable[temp].push_back(effect);
	}
}

void EffectManager::Play(string name, Vector2 pos)
{
	if (_effectTable.count(name) == 0)
		return;

	for (auto effect : _effectTable[name])
	{
		if (effect->isActive == false)
		{
			effect->Play(pos);
			break;
		}
	}
}

void EffectManager::Update()
{
	for (auto pair : _effectTable)
	{
		for (auto effect : pair.second)
		{
			effect->Update();
		}
	}
}

void EffectManager::Render()
{
	for (auto pair : _effectTable)
	{
		for (auto effect : pair.second)
		{
			effect->Render();
		}
	}
}
