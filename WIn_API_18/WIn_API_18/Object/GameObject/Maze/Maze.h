#pragma once
class Maze
{
public:
	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMap();
private:
	shared_ptr<MazeBlock> _blocks [25][25];

	UINT _poolCountX = 25;
	UINT _poolCountY = 25;
};

