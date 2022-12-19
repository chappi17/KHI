#include "framework.h"
#include "Player.h"

Player::Player()
{
	_quad = make_shared<Quad>(L"Player.png", Vector2(200, 200));
	_gun = make_shared<Gun>();
	_gun->GetTransform()->SetParent(_quad->GetTransform());
	_gun->GetTransform()->Getpos()._x += 100;
}

Player::~Player()
{
}

void Player::Update()
{
	_quad->Update();
	
	Vector2 temp = mousePos - _gun->GetTransform()->GetWorldPos();
	float angle = temp.Angle();
	_gun->GetTransform()->GetAngle() = angle;

	_gun->Update();
}

void Player::Render()
{
	_quad->Render();

	_gun->Render();

}

void Player::Move(const Vector2& pos)
{
	_quad->GetTransform()->Getpos() = pos;
}

void Player::Fire(const Vector2& mousePos)
{
	_gun->FireBullet(mousePos);
}
