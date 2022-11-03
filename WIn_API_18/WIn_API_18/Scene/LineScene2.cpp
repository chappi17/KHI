#include "framework.h"
#include "LineScene2.h"

LineScene2::LineScene2()
{
	_line1 = make_shared<Line>(Vector2(50, 500), Vector2(800, 500));
	_line2 = make_shared<Line>(Vector2(50, 100), Vector2(50, 100));
	_line3 = make_shared<Line>(Vector2(50, 450), Vector2(100, 450));
}

LineScene2::~LineScene2()
{
	
}

void LineScene2::Update()
{
	_line1->Update();
	_line2->Update();
	_line3->Update();

	_line2->_endPos = mousePos;

	Vector2 line2Vec = _line2->_endPos - _line2->_startPos;
	Vector2 line1Vec = _line1->_endPos - _line1->_startPos;  // 벡터의 선
	line1Vec= line1Vec.Normalize();

	// 내적
	float dot = (line2Vec._x * line1Vec._x) + (line2Vec._y * line1Vec._y);

	_line3->_endPos = { _line3->_startPos + line1Vec * dot };

	
}

void LineScene2::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_line3->Render(hdc);
}
