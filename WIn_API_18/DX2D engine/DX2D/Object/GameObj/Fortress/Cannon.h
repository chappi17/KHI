#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render();

	void Set(const Vector2 pos);
	
	void Fire();		
	
private:
	void Move();

	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _circleCol;
	shared_ptr<class Barrel> _barrel;
	shared_ptr<Transform> _rotation;

	float _angle = 0.0f;
	float _speed = 300.0f;
};