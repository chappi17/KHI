#pragma once
class EffectManager
{
public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new EffectManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static EffectManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

			return nullptr;
	}

	void AddEffect(wstring path, Vector2 maxFrame, Vector2 size ,float speed = 0.1f, Action::Type type = Action::Type::END);
	void Play(string name, Vector2 pos);

	void Update();
	void Render();

private:
	EffectManager();
	~EffectManager();

	static EffectManager* _instance;

	const int _poolCount = 30;
	unordered_map<string, vector<shared_ptr<Effect>>> _effectTable;
};

