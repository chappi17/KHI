#pragma once
class D_Player
{
public:
	D_Player();
	~D_Player();

	UINT& GetHp() { return _hp; }

	void SetLeftRight(Vector2 leftright) { _LeftRight = leftright; }

	void Update();
	void Render();

	shared_ptr<Collider> GetCollider() { return _rectCol; }

	bool _isActive = true;

private:
	void Move();

	UINT _hp = 10;


	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _rectCol;
	Vector2 _LeftRight = { 0,WIN_WIDTH };
	
	float _speed = 300.0f;


};

