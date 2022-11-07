#include "framework.h"
#include "Barrel.h"

Barrel::Barrel()
{
}

Barrel::~Barrel()
{
}

void Barrel::Update()
{
}

void Barrel::Render(HDC hdc)
{
	// 시작점 끝점 
	MoveToEx(hdc, _startPos._x, _startPos._y, nullptr);
		LineTo(hdc, _endPos._x, _endPos._y);
}
