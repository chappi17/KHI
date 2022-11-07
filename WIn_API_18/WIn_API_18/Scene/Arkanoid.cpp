#include "framework.h"
#include "Arkanoid.h"

Arkanoid::Arkanoid()
{
	_map = make_shared<Map>();
	_bar = make_shared<Bar>();
	_ball.emplace_back(make_shared<Ball>());
	_mainball = make_shared<CircleCollider>(Vector2{ CENTER_X, 580 }, 10);
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
	if (_isActiveMyBall == true)
		if (_ball.front()->_isActive == false)
		{
			_isActiveMyBall = false;
		}

	if (GetAsyncKeyState(VK_LEFT))
		_bar->MoveLeft();
	if (GetAsyncKeyState(VK_RIGHT))
		_bar->MoveRight();
	if (GetAsyncKeyState(VK_SPACE))
	{
		
		_map->Update();
		_bar->Update();

		for (auto& ball : _ball)
			ball->Update();
		_mainball->_center = MYBALL->GetBall()->_center;
		_mainball->Update();
	}
}

void Arkanoid::Render(HDC hdc)
{
	_map->Render(hdc);
	_bar->Render(hdc);
	_mainball->Render(hdc);
}
