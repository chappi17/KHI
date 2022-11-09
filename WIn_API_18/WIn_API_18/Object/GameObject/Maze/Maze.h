#pragma once
class Maze
{
public:
	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMap();

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

