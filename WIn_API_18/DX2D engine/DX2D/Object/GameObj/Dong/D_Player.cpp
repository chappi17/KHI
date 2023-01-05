#include "framework.h"
#include "D_Player.h"

D_Player::D_Player()
{
	_quad = make_shared<Quad>(L"Player.png", Vector2(150, 150));

	_rectCol = make_shared<RectCollider>(Vector2(100, 140));
	_rectCol->GetTransform()->SetParent(_quad->GetTransform());

	_quad->GetTransform()->Getpos() = Vector2(CENTER_X, CENTER_Y - 280);
}

D_Player::~D_Player()
{
}

void D_Player::Update()
{
	if (_isActive == false)
		return;
	Move();

	_quad->Update();
	_rectCol->Update();
}

void D_Player::Render()
{
	if (_isActive == false)
		return;
	_quad->Render();
	_rectCol->Render();

}

void D_Player::Move()
{
	if (KEY_PRESS('A') && (_quad->GetTransform()->Getpos().x-50 > _LeftRight.x))
		{
			_quad->GetTransform()->Getpos().x -= _speed * DELTA_TIME;
		}
	
	if (KEY_PRESS('D') && ((_quad->GetTransform()->Getpos().x+50 < _LeftRight.y)))
		{
			_quad->GetTransform()->Getpos().x += _speed * DELTA_TIME;
		}
}