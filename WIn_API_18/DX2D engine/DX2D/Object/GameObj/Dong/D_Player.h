#pragma once
class D_Player
{
public:
	D_Player();
	~D_Player();

	UINT& GetHp() { return _hp; }

	void Update();
	void Render();

	shared_ptr<Collider> GetCollider() { return _rectCol; }

	bool _isActive = true;

private:
	void Move();

	UINT _hp = 10;

	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _rectCol;
	
	float _speed = 300.0f;


};

