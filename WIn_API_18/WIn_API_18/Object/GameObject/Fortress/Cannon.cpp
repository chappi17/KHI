#include "framework.h"

Cannon::Cannon()
{
	
	_body = make_shared<CircleCollider>(Vector2(CENTER_X,CENTER_Y),30);	
	_barrel = make_shared<Barrel>();
	
	_barrel->_startPos = _body->GetCenter();
	_barrel->_endPos = _barrel->_startPos + Vector2(_barrelSize, 0); // º± ¡¶¿€ 

	_bullets.reserve(30);
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->SetActive(false);
		_bullets.push_back(bullet);
	}
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	if (_isActive == false)
		return;

	for (auto& bullet : _bullets)
		bullet->Update();
	
	_barrel->Update();
	_body->Update();
	

	_barrel->_startPos = _body->GetCenter();
	_barrel->_endPos._x = _body->GetCenter()._x + _barrelSize * cosf(_angle);
	_barrel->_endPos._y = _body->GetCenter()._y + _barrelSize * sinf(_angle);

	//Vector2 temp = _bullet->GetCenter();
	//temp._x +=  * cosf(_angle);
	//temp._y +=  * sinf(_angle);
	//_bullet->SetCenter(temp);
}

void Cannon::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	for (auto& bullet : _bullets)
		bullet->Render(hdc);
	
	_barrel->Render(hdc);
	_body->Render(hdc);
	
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

void Cannon::Fire()
{
	auto iter = _bullets.begin();

	iter = std::find_if(_bullets.begin(), _bullets.end(), [](const shared_ptr<Bullet> b) -> bool
		{
			if (b->IsActive() == false)
				return true;
			return false;
		});

	if (iter == _bullets.end())
		return;

	Vector2 dir = _barrel->_endPos - _body->GetCenter();
	(*iter)->SetActive(true);
	(*iter)->SetPos(_barrel->_endPos);
	(*iter)->Fire(dir);	
}

bool Cannon::IsCollision(shared_ptr<Bullet> bullet)
{
	if (_isActive == false)
		return false;

	if (_body->IsCollision(bullet->GetCollider()))
		return true;

	return false;
}
