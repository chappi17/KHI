#pragma once
class StateManager
{
private:
	StateManager();
	~StateManager();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new StateManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static StateManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	shared_ptr<SamplerState> GetSampler() { return _samplerState; }
	shared_ptr<BlendState> GetAlphaBlend() { return _alphaState; }
	shared_ptr<BlendState> GetAdditiveBlend() { return _additiveState; }

private:
	static StateManager* _instance;

	shared_ptr<SamplerState> _samplerState;
	shared_ptr<BlendState> _alphaState;
	shared_ptr<BlendState> _additiveState;
};
