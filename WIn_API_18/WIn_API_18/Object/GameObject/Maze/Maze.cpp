#include "framework.h"
#include "Maze.h"

Maze::Maze()
{
	Vector2 offset = Vector2{ CENTER_X * 0.5f + 50.0f, CENTER_Y * 0.5f -100.0f };
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<MazeBlock> block = make_shared<MazeBlock>();
			
			block->SetCenter(Vector2(19 * x + offset._x, 19 * y + offset._y));
			block->Type() = MazeBlock::BlockType::ABLE;
			_blocks[y][x] = block; // 움직이는 기준 약속점.
		}
	}
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			_blocks[y][x]->Update();
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			_blocks[y][x]->Render(hdc);
		}
	}
}

void Maze::CreateMap()
{
}
