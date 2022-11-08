#pragma once
class Ball;

class Bar
{
public:
	Bar();
	~Bar();

	void Update();
	void Render(HDC hdc);

	shared_ptr<RectCollider> Getbar() { return _bar; }

	void MoveLeft();
	void MoveRight();	

	bool IsCollision(shared_ptr<Ball> ball);	

private:
	shared_ptr<RectCollider> _bar;
	shared_ptr<CircleCollider> _ball;
	float _speed = 3.0f;
};

