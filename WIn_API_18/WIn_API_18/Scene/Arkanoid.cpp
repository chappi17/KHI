#include "framework.h"
#include "Arkanoid.h"

Arkanoid::Arkanoid()
{
	_map = make_shared<Map>();
	_bar = make_shared<Bar>();
	_ball = make_shared<Ball>();

	_screen = make_shared<RectCollider>();
	_screen->_center =(Vector2(CENTER_X, 100), Vector2(410, 510));

	_ball->_isActive = true;
	//_mainball = make_shared<CircleCollider>(Vector2{ CENTER_X, 580 }, 10);
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
	if (_isActiveMyBall == false)

		if (GetAsyncKeyState(VK_LEFT))
			_bar->MoveLeft();
	if (GetAsyncKeyState(VK_RIGHT))
		_bar->MoveRight();
	if (GetAsyncKeyState(VK_SPACE))

	_map->Update();
	_bar->Update();
	_ball->Update();
	_screen->Update();

	

	if (_bar->IsCollision(_ball) == true)
	{
		float vector_x = _bar->Getbar()->GetCenter()._x - _ball->GetBall()->GetCenter()._x;
		float vector_y = _bar->Getbar()->GetCenter()._y - _ball->GetBall()->GetCenter()._y;

		if (_ball->GetBall()->GetCenter()._x <= _bar->Getbar()->GetCenter()._x +50)
		{
			_ball->SetDir(Vector2(-vector_x, vector_y));
		}
		if (_ball->GetBall()->GetCenter()._y >= _bar->Getbar()->GetCenter()._y - 20)
		{
			_ball->SetDir(Vector2(vector_x, -vector_y));
		}
	

		//_mainball->_center = MYBALL->GetBall()->_center;
		//_mainball->Update();	
	}
}

void Arkanoid::Render(HDC hdc)
{
	_map->Render(hdc);
	_bar->Render(hdc);
	_ball->Render(hdc);
	_screen->Render(hdc);

	

	//_mainball->Render(hdc);
}
