#pragma once

struct Kruskal_edge
{
	int cost;
	Vector2 u;
	Vector2 v;

	bool operator < (const Kruskal_edge& edge)const
	{
		if (cost < edge.cost)
			return true;
		return false;
	}
};

class Maze
{
public:
	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMap();
	void CreateMap_Kruskal();

	Vector2 GetStartPos() { return Vector2(1, 1); }
	Vector2 GetEndPos() { return Vector2(23, 23); }

	void SetPlayer(shared_ptr<MazePlayer> p) { _player = p; }
	MazeBlock::BlockType GetBlockType(const Vector2& pos);
	shared_ptr<MazeBlock> GetBlock(const Vector2& pos);

private:
	shared_ptr<MazePlayer> _player;
	shared_ptr<MazeBlock> _blocks[25][25];

	UINT _poolCountX = 25;
	UINT _poolCountY = 25;
};

