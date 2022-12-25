#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render();


private:

	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _rectCol;
};

