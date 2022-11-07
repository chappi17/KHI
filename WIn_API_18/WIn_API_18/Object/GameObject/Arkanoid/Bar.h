#pragma once
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

	void Fire(Vector2 vector);

private:
	shared_ptr<RectCollider> _bar;
	float _speed = 3.0f;
	


};

