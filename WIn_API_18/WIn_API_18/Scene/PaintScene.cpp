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

	_rect1 = make_shared<RectCollider>(Vector2(100, 150), Vector2(150, 150));
	_rect2 = make_shared<RectCollider>(Vector2(500, 150), Vector2(150, 150));


	_circle1 = make_shared<CircleCollider>(Vector2(100.0f,400.0f), 50);
	_circle2 = make_shared<CircleCollider>(Vector2(500.0f,400.0f), 50);
	_circle3 = make_shared<CircleCollider>(Vector2(900.0f,400.0f), 50);
}

PaintScene::~PaintScene()
{
	
}

void PaintScene::Update()

{
	_circle3->SetCenter(mousePos);

	if (_circle1->IsCollision(mousePos))
		_circle1->SetRED();
	else
		_circle1->SetGREEN();

	if (_circle2->IsCollision(_circle3))
		_circle2->SetRED();
	else
		_circle2->SetGREEN();

	if (_rect1->IsCollision(mousePos))
		_rect1->SetRED();
	else
		_rect1->SetGREEN();
	
	if (_rect2->IsCollision(mousePos))
		_rect2->SetRED();
	else
		_rect2->SetGREEN();

	//_rect->GetCenter()._x += 0.5f;

	//Vector2 start = _circle1->GetCenter();
	//Vector2 dest = mousePos;
	//Vector2 result = dest - start; // ***** 두 사이의 벡터 구하려면 dest 에서 star 빼면 된다. 복습하자 이거 어렵다
	//Vector2 normal =result.Normalize();

	//_circle->GetCenter() += normal;

	// 선형보간 -> 멀면 빨리 다가가고, 가까우면 느리게 다가감
	//_circle->GetCenter() = { 300.0f, 300.0f };
		
		// LERP(start, dest, 0.04f);	
}

void PaintScene::Render(HDC hdc)
{
	// 선은 파랑색
	// 원 내부를 빨강, 선을 파랑
	// 사각형 내부를 초록, 선을 파랑
	//SelectObject(hdc, _pens[2]);
	//SelectObject(hdc, _brushes[0]);	

	//MoveToEx(hdc, 150, 150, NULL);
	//LineTo(hdc, mousePos._x, mousePos._y); // 렌더 순서가 중요함. 겹치면 -> 먼저 그려진게 안으로 그려짐

	//SelectObject(hdc, _pens[2]);
	_circle3->Render(hdc);


	//SelectObject(hdc, _brushes[1]);
	_rect1->Render(hdc);
	_rect2->Render(hdc);
	//Rectangle(hdc, 150, 150, 300, 300); // 회전 불가능 

	//SelectObject(hdc, _pens[2]);
	//SelectObject(hdc, _brushes[0]);
	_circle1->Render(hdc);
	_circle2->Render(hdc);
	//Ellipse(hdc, 50, 50, 150, 150); -> 과제 움직이는 원 구현하기 
	
	//Collider -> 충돌체

	//Win api 창은 픽셀로 되어있음(int 형이란 얘기)-> 어지간하면 int로 되어있다.
	// Render 하는 곳에는 다 int 
}
