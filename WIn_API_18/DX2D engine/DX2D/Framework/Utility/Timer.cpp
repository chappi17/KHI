#include "framework.h"
#include "Timer.h"

Timer* Timer::_instance = nullptr;
Timer::Timer()
{
	// 1�ʵ��� CPU�� �������� ��ȯ�ϴ� �Լ� 
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);

	// ���� ������ ����
	QueryPerformanceCounter((LARGE_INTEGER*)& _lasTime);

	_timeScale = 1.0f / (double)_periodFrequency; // �ð��� �Ը� �ٸ���.  ���ӿ��� �帣�� �⺻ �ð� �ø����� ������

}

Timer::~Timer()
{
}

void Timer::Update()
{
	// ���ݱ��� ������ Ƚ�� - ó���� ������ Ƚ��) * (1/ �ʴ� ������ Ƚ��)
	// (10000 -0) * (_timeScale)
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);

	if (_lockFPS != 0)
	{
		while (_timeElased < (1.0f / _lockFPS))
		{
			// �� �����Ӹ�ŭ ����� �ð� 
			QueryPerformanceCounter((LARGE_INTEGER*)& _curTime);
			_timeElased = (double)(_curTime - _lasTime) * _timeScale;
		}
	}
	else
	{
		_timeElased = (double)(_curTime - _lasTime) * _timeScale;
	}

	_lasTime = _curTime;

	_frameCount++; // �츮�� ���� ������ (FPS)
	_oneSecCount += _timeElased; // Update �ѹ��� ����� �ð� = delta time = �ð� ��ȭ��

	// 1�ʸ��� �����ؾ� �ϴ� ����

	if (_oneSecCount >= 1)
	{
		_frameRate = _frameCount;
		// frameRate : FPS (Frame Per Second)
		_frameCount = 0;
		_oneSecCount = 0;
	}

	// �� ����� �ð�
	_runTime += _timeElased;
}
