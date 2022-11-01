#pragma once
class Cannon
{

public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void MoveLeft();
	void MoveRight();

	void SetRED();

	shared_ptr<CircleCollider> GetBody() { return _body; }
	shared_ptr<CircleCollider> Get_EnemyBody() { return _ebody; }
	shared_ptr<CircleCollider> Get_bullet() { return _bullet; }
	
	

	float& GetAngle() {return _angle; }

	bool _isActive = true;

	void Fire();

private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<CircleCollider> _ebody;
	shared_ptr<Barrel> _barrel;
	shared_ptr<CircleCollider> _bullet;

	HPEN _curPen;
	HPEN _pens[2];


	int _hp;

	float _speed = 2.0f;
	float _speed2 = 10.0f;
	// 각으로 움직인다. 
	float _angle = 0.0f; 

	float _barrelSize = 60.0f;

	//shared_ptr<Bullet> _bullet;
};

