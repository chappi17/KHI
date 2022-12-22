#pragma once
class D_Player
{
public:
	D_Player();
	~D_Player();

	void Update();
	void Render();

	shared_ptr<Collider> GetCollider() { return _rectCol; }
	bool _isActive = true;

private:

	void Move();
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _rectCol;
	
	float _speed = 300.0f;


};

