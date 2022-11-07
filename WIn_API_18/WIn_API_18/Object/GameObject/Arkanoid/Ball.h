#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 vector);
	
	void SetPos(Vector2 pos)
	{
		_ball->_center = pos;
	}
	
	bool IsCollision(shared_ptr<RectCollider> col) { return _ball->IsCollision(col); }
	shared_ptr<CircleCollider> GetBall() { return _ball; }
	Vector2 _moveVector = { 0.0f,0.0f };
		bool _isActive = false;

private:
	shared_ptr<CircleCollider> _ball;
	Vector2 _dir = Vector2();	
	float _speed = 10.0f;
	
};

