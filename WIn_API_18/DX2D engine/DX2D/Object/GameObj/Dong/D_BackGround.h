#pragma once
class D_BackGround
{
public:
	D_BackGround();
	~D_BackGround();

	Vector2 LeftRight();

	void Update();
	void Render();

private:

	shared_ptr<Quad> _quad;

};

