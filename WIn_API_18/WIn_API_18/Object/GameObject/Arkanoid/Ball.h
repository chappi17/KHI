#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 dir);		
	shared_ptr<CircleCollider> GetBall() { return _ball; }	
	Vector2 GetDir() { return _dir; }
	void SetDir(Vector2 dir) { _dir = dir; }
	void SetActive(bool value) { _isActive = value; }

		bool _isActive = false;	

private:
	shared_ptr<CircleCollider> _ball;
	Vector2 _dir = Vector2(0, -1);
	float _speed = 3.0f;
	
};

