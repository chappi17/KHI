#include "framework.h"
#include "Timer.h"

Timer* Timer::_instance = nullptr;
Timer::Timer()
{
	// 1초동안 CPU의 진동수를 반환하는 함수 
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);

	// 현재 진동수 총합
	QueryPerformanceCounter((LARGE_INTEGER*)& _lasTime);

	_timeScale = 1.0f / (double)_periodFrequency; // 시간의 규모가 다르다.  게임에서 흐르는 기본 시간 늘릴수록 빨라짐

}

Timer::~Timer()
{
}

void Timer::Update()
{
	// 지금까지 진동한 횟수 - 처음에 진동한 횟수) * (1/ 초당 진동한 횟수)
	// (10000 -0) * (_timeScale)
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);

	if (_lockFPS != 0)
	{
		while (_timeElased < (1.0f / _lockFPS))
		{
			// 한 프레임만큼 경과한 시간 
			QueryPerformanceCounter((LARGE_INTEGER*)& _curTime);
			_timeElased = (double)(_curTime - _lasTime) * _timeScale;
		}
	}
	else
	{
		_timeElased = (double)(_curTime - _lasTime) * _timeScale;
	}

	_lasTime = _curTime;

	_frameCount++; // 우리가 보는 프레임 (FPS)
	_oneSecCount += _timeElased; // Update 한번에 경과된 시간 = delta time = 시간 변화량

	// 1초마다 갱신해야 하는 정보

	if (_oneSecCount >= 1)
	{
		_frameRate = _frameCount;
		// frameRate : FPS (Frame Per Second)
		_frameCount = 0;
		_oneSecCount = 0;
	}

	// 총 경과된 시간
	_runTime += _timeElased;
}
