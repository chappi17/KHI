#include "framework.h"
#include "MazeBlock.h"

MazeBlock::MazeBlock()
{
	_rect = make_shared<RectCollider>(Vector2(), Vector2(15, 15));

	_brushes.reserve(6);

	_brushes.push_back(CreateSolidBrush(GREEN));
	_brushes.push_back(CreateSolidBrush(RED));
	_brushes.push_back(CreateSolidBrush(CYAN));
	_brushes.push_back(CreateSolidBrush(WHITE));
	_brushes.push_back(CreateSolidBrush(GRAY));
	_brushes.push_back(CreateSolidBrush(BLACK));
}

MazeBlock::~MazeBlock()
{
}

void MazeBlock::Update()
{
	_rect->Update();
}

void MazeBlock::Render(HDC hdc)
{
	switch (_type)
	{
	case MazeBlock::BlockType::ABLE:
		SelectObject(hdc, _brushes[static_cast<UINT>(BlockType::ABLE)]);
		break;
	case MazeBlock::BlockType::DISABLE:
		SelectObject(hdc, _brushes[static_cast<UINT>(BlockType::DISABLE)]);
		break;
	case MazeBlock::BlockType::END:
		SelectObject(hdc, _brushes[static_cast<UINT>(BlockType::END)]);
		break;
	case MazeBlock::BlockType::PLAYER:
		SelectObject(hdc, _brushes[static_cast<UINT>(BlockType::PLAYER)]);
		break;
	case MazeBlock::BlockType::FOOTPRINT:
		SelectObject(hdc, _brushes[static_cast<UINT>(BlockType::FOOTPRINT)]);
		break;
	case MazeBlock::BlockType::NONE:
		SelectObject(hdc, _brushes[static_cast<UINT>(BlockType::NONE)]);
		break;
		break;
	default:
		break;
	}
	_rect->Render(hdc);
}
