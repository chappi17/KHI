#include "framework.h"
#include "Block.h"

Block::Block()
{
	_rectcol = make_shared<RectCollider>(Vector2(CENTER_X, CENTER_Y), Vector2(40, 20));
}

Block::~Block()
{
}

void Block::Update()
{
	if (_isActive == false)
		return;

	_rectcol->Update();
}

void Block::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	_rectcol->Render(hdc);
}
