#include "framework.h"
#include "Action.h"

Action::Action(vector<Clip> clips, string name, Type type, float speed)
:_name(name)
,_repeatType(type)
,_speed(speed)
,_clips(clips)
{
}

Action::~Action()
{
}

void Action::Update()
{
	if (_isPlay == false)
		return;

	_time += DELTA_TIME;

	if (_time > _speed)
	{
		_time = 0.0f;

		switch (_repeatType)
		{
		case Action :: END:
		{
			_curClipNum++;
			if (_curClipNum >= _clips.size())
				Stop();
		}
			break;
		case Action::LOOP:
		{
			_curClipNum++;
			_curClipNum %= _clips.size();
		}
			break;
		case Action::PINGPONG:
		{
			if (_isReverse)
			{
				_curClipNum--;
				if (_curClipNum <= 0)
					_isReverse = false;
			}
			else
			{
				_curClipNum++;
				if (_curClipNum >= _clips.size()-1)
					_isReverse = true;
			}
		}
			break;
		default:
			break;
		}
	}
}

void Action::Play()
{
	_isPlay = true;
	_isReverse = false;
	_time = 0.0f;
	_curClipNum = 0;
}

void Action::Pause()
{
	_isPlay = false;
}

void Action::Stop()
{
	_isPlay = false;
	_curClipNum = 0;
	if (_endEvent != nullptr)
		_endEvent();
	if (_testEvent != nullptr)
		_testEvent(0);
}

void Action::Reset()
{
	_isPlay = false;
	_curClipNum = 0;
	_time = 0.0f;
}