#pragma once
class Ball;

class Map
{
public:

	Map();
	~Map();

	void Update();
	void Render(HDC hdc);

	
private:

	UINT _poolCount = 40;

	Vector2 _offset = { 500,200 };
	Vector2 _gap = { 6,6 };

	vector<shared_ptr<Block>> _blocks;
	shared_ptr<Ball> _ball;
	
};

