#include "framework.h"

Cannon::Cannon()
{
	
	_body = make_shared<CircleCollider>(Vector2(CENTER_X,CENTER_Y),30);
	_ebody = make_shared<CircleCollider>(Vector2(1200,CENTER_Y),30);
	_barrel = make_shared<Barrel>();
	_bullet = make_shared<CircleCollider>(Vector2(_body->GetCenter()._x, _body->GetCenter()._y), 10);
	_barrel->_startPos = _body->GetCenter();
	_barrel->_endPos = _barrel->_startPos + Vector2(_barrelSize, 0); // ¼± Á¦ÀÛ 
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	_bullet->Update();
	_barrel->Update();
	_body->Update();
	_ebody->Update();

	_barrel->_startPos = _body->GetCenter();
	_barrel->_endPos._x = _body->GetCenter()._x + _barrelSize * cosf(_angle);
	_barrel->_endPos._y = _body->GetCenter()._y + _barrelSize * sinf(_angle);

	Vector2 temp = _bullet->GetCenter();
	temp._x += _speed2 * cosf(_angle);
	temp._y += _speed2 * sinf(_angle);
	_bullet->SetCenter(temp);
}

void Cannon::Render(HDC hdc)
{
	_bullet->Render(hdc);
	_barrel->Render(hdc);
	_body->Render(hdc);
	_ebody->Render(hdc);
}

void Cannon::MoveLeft()
{
	Vector2 temp = _body->GetCenter();
	temp._x -= _speed;
	_body->SetCenter(temp);
}

void Cannon::MoveRight()
{
	Vector2 temp = _body->GetCenter();
	temp._x += _speed;
	_body->SetCenter(temp);
}

void Cannon::SetRED()
{
	_curPen = _pens[0];
}

void Cannon::Fire()
{
	_bullet = make_shared<CircleCollider>(Vector2(_body->GetCenter()._x, _body->GetCenter()._y), 10);
	
}
