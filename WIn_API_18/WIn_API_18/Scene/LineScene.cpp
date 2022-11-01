#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Line>(Vector2(100,100), Vector2(500,500));
	_line2 = make_shared<Line>(Vector2(100,500), Vector2(500,100));
	_circle = make_shared<CircleCollider>(Vector2(0, 0), 5);
}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	_line1->Update();
	_line2->Update();
	_circle->Update();

	_line2->_endPos = mousePos;
	
	Line::Result chk = _line1->IsCollision(_line2);
	if (chk.collision)
	{
		_line1->SetRED();
		_line2->SetRED();
		_circle->SetCenter(chk.conflict);
	}
	else
	{
		_line1->SetGREEN();
		_line2->SetGREEN();
	}
}

void LineScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_circle->Render(hdc);
}
