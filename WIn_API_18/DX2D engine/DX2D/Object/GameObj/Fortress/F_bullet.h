#pragma once
class F_bullet
{
public:
	F_bullet();
	~F_bullet();

	void Update();
	void Render();	

	void Fire(Vector2 dir);

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	
	void SetDir(const Vector2& dir) { _dir = dir.Normal(); }

	bool _isActive = false;

private:
	double		_lastTime = 0.0;
	double		_curTime = 0.0;
	double		_delay = 3.0;


	float		_speed = 500.0f;
	Vector2		_dir = Vector2();


	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _circleCol;
};