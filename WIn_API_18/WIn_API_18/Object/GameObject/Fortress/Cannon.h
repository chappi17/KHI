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
	void MoveDown();		
	void Fire();

	shared_ptr<CircleCollider> GetBody() { return _body; }
	const float& GetAngle() {return _angle; }
	void SetAngle(float angle) { _angle = angle; }

	bool IsCollision(shared_ptr <Bullet> bullet);
	vector<shared_ptr<Bullet>> GetBullests() { return _bullets; }

	bool _isActive = true;

private:
	shared_ptr<CircleCollider> _body;	
	shared_ptr<Barrel> _barrel;
	// 애초에 메모리풀 잡는다.
	vector<shared_ptr<Bullet>> _bullets;

	UINT _poolCount = 30;
	float _speed = 2.0f;	
	// 각으로 움직인다. 
	float _angle = 0.0f; 

	float _barrelSize = 60.0f;

};

