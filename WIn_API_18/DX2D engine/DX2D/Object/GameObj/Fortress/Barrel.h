#pragma once
class Barrel
{
public:
	Barrel();
	~Barrel();

	void Update();
	void Render();

	void FireBullet();
	void MoveAngle();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform();}
	
private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _rectCol;	
	shared_ptr<Transform> _barrelTrans;	

	UINT _poolCount = 20;
	vector<shared_ptr<class F_bullet>> _bullets;
	
	float _speed = 300.0f;
};

