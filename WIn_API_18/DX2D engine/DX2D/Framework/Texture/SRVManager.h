#pragma once
class SRVManager
{
private:
	SRVManager();
	~SRVManager();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new SRVManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static SRVManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	shared_ptr<SRV> AddSRV(wstring file);

private:
	// 판박이가 딱 한장 있어도 같은 이미지로 여러개의 사각형에 맵핑할 수 있다.
	static SRVManager* _instance;

	unordered_map<wstring, shared_ptr<SRV>> _srvTable;
};

