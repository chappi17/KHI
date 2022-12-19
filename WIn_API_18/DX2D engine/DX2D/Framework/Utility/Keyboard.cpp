#include "framework.h"
#include "Keyboard.h"

Keyboard* Keyboard::_instance = nullptr;

Keyboard::Keyboard()
	: _curState{}
	, _oldState{}
	, _mapState{}
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update()
{
	std::memcpy(_oldState, _curState, sizeof(_oldState));

	GetKeyboardState(_curState);

	for (int i = 0; i < KEYMAX; i++)
	{
		byte key = _curState[i] & 0x80;
		_curState[i] = key ? 1 : 0;

		byte old = _oldState[i];
		byte cur = _curState[i];

		if (old == 0 && cur == 1)
		{
			_mapState[i] = DOWN;
		}
		else if (old == 1 && cur == 0)
		{
			_mapState[i] = UP;
		}
		else if (old == 1 && cur == 1)
		{
			_mapState[i] = PRESS;
		}
		else
		{
			_mapState[i] = NONE;
		}
	}
}
