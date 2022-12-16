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

	GetKeyboardState(_curState); // 현재 누르고 있는지 _curState에 저장됨

	for (int i = 0; i < KEYMAX; i++)
	{
		byte key = _curState[i] & 0x80;
		// true 면 왼쪽 false 면 오른쪽
		_curState[i] = key ? 1 : 0;

		byte old = _oldState[i];
		byte cur = _curState[i];

		if (old == 0 && cur == 1) // old 는 안누른거, cur은 누른거 
		{
			_mapState[i] = DOWN; // 입력한 상태
		}
		else if (old == 1 && cur == 0)
		{
			_mapState[i] = UP; // 뗀 상태
		}
		else if (old == 1 && cur == 1)
		{
			_mapState[i] = PRESS; // 누르고 있는 상태 
		}
		else
		{
			_mapState[i] = NONE;
		}
	}


}
