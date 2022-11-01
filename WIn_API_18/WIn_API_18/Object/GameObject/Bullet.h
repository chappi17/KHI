#pragma once
class Bullet
{
public:

	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);



	Vector2 _startPos;
	Vector2 _endPos;

private:

};

