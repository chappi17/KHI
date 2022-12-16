#pragma once

#define KEYMAX 255
class Keyboard
{
private:
	enum
	{
		NONE,
		DOWN,
		UP,
		PRESS
	};

	Keyboard();
	~Keyboard();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new Keyboard();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Keyboard* GetInstance()
	{
		if (_instance != nullptr)
		{
			return _instance;
		}
		return nullptr;
	}

	void Update();

	bool Down(UINT key) { return _mapState[key] == DOWN; }
	bool Up(UINT key) { return _mapState[key] == UP; }
	bool Press(UINT key) { return _mapState[key] == PRESS; }

	Vector2& GetMousePos() { return _mousePos; }

private:
	static Keyboard* _instance;

	byte _curState[KEYMAX];
	byte _oldState[KEYMAX];
	byte _mapState[KEYMAX];

	Vector2 _mousePos = { 0.0f,0.0f };
};

