#pragma once
class Barrel
{
public:
	Barrel();
	~Barrel();

	void Update();
	void Render(HDC hdc);	

	Vector2 _startPos;
	Vector2 _endPos;

private:
	
};

