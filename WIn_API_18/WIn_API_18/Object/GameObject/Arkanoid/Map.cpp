#include "framework.h"
#include "Map.h"

Map::Map()
{
	_blocks.reserve(_poolCount);

		for (int i = 0; i < _poolCount; i++)
		{
			shared_ptr<Block> block = make_shared<Block>();
			block->_isActive = true;
			_blocks.push_back(block);
		}

		int maxX = 8;
		int maxY = 5;
		Vector2 blockSize = _blocks[0]->GetBlockSize();

		for (int y = 0; y < maxY; y++)
		{
			for (int x = 0; x < maxX; x++)
			{
				int index = x + y * maxX;

				Vector2 pos;
				pos._x = blockSize._x * x + _gap._x * x;
				pos._y = blockSize._y * y + _gap._y * y;
				pos += _offset;

				_blocks[index]->SetPos(pos);
			}
		}
}

Map::~Map()
{
	
}

void Map::Update()
{
	for (auto& block : _blocks)
		block->Update();

	for (auto& block : _blocks)
	{
		if (block->IsCollision(_ball) == true)
		{
			float before_x = _ball->GetDir()._x;
			float before_y = _ball->GetDir()._y;

			block->_isActive = false;
			if (_ball->GetBall()->GetCenter()._x <= block->GetBlock()->GetCenter()._x + 30
				|| _ball->GetBall()->GetCenter()._x >= block->GetBlock()->GetCenter()._x - 30)
			{
				_ball->SetDir(Vector2(-before_x, before_y));
			}
			if (_ball->GetBall()->GetCenter()._y >= block->GetBlock()->GetCenter()._x - 20
				|| _ball->GetBall()->GetCenter()._y <= block->GetBlock()->GetCenter()._x + 20)
			{
				_ball->SetDir(Vector2(before_x, -before_y));
			}
		}
	}
}

void Map::Render(HDC hdc)
{
	for (auto& block : _blocks)
		block->Render(hdc);
}


