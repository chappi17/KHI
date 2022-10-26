#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_brushes[0] = CreateSolidBrush(RED); // 빨강
	_brushes[1] = CreateSolidBrush(GREEN); // 빨강
	_brushes[2] = CreateSolidBrush(BLUE); // 빨강

	_pens[0] = CreatePen(0, 3, RED);
	_pens[1] = CreatePen(0, 3, GREEN);
	_pens[2] = CreatePen(0, 3, BLUE);

	_rect = make_shared<RectCollider>(Vector2(225, 255), Vector2(150, 150));
}

PaintScene::~PaintScene()
{
	
}

void PaintScene::Update()
{
	_rect->GetCenter()._x += 0.5f;
}

void PaintScene::Render(HDC hdc)
{

	// 선은 파랑색
	// 원 내부를 빨강, 선을 파랑
	// 사각형 내부를 초록, 선을 파랑
	SelectObject(hdc, _pens[2]);
	SelectObject(hdc, _brushes[0]);	

	MoveToEx(hdc, 150, 150, NULL);
	LineTo(hdc, mousePosX, mousePosY); // 렌더 순서가 중요함. 겹치면 -> 먼저 그려진게 안으로 그려짐

	SelectObject(hdc, _pens[2]);
	SelectObject(hdc, _brushes[1]);
	//Rectangle(hdc, 150, 150, 300, 300); // 회전 불가능 
	_rect->Render(hdc);

	SelectObject(hdc, _pens[2]);
	SelectObject(hdc, _brushes[0]);
	//Ellipse(hdc, 50, 50, 150, 150); -> 과제 움직이는 원 구현하기 
	//Collider -> 충돌체

}
