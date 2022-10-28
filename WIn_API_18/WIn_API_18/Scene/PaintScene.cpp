#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_brushes[0] = CreateSolidBrush(RED); // ����
	_brushes[1] = CreateSolidBrush(GREEN); // ����
	_brushes[2] = CreateSolidBrush(BLUE); // ����

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
	//Vector2 result = dest - start; // ***** �� ������ ���� ���Ϸ��� dest ���� star ���� �ȴ�. �������� �̰� ��ƴ�
	//Vector2 normal =result.Normalize();

	//_circle->GetCenter() += normal;

	// �������� -> �ָ� ���� �ٰ�����, ������ ������ �ٰ���
	//_circle->GetCenter() = { 300.0f, 300.0f };
		
		// LERP(start, dest, 0.04f);	
}

void PaintScene::Render(HDC hdc)
{
	// ���� �Ķ���
	// �� ���θ� ����, ���� �Ķ�
	// �簢�� ���θ� �ʷ�, ���� �Ķ�
	//SelectObject(hdc, _pens[2]);
	//SelectObject(hdc, _brushes[0]);	

	//MoveToEx(hdc, 150, 150, NULL);
	//LineTo(hdc, mousePos._x, mousePos._y); // ���� ������ �߿���. ��ġ�� -> ���� �׷����� ������ �׷���

	//SelectObject(hdc, _pens[2]);
	_circle3->Render(hdc);


	//SelectObject(hdc, _brushes[1]);
	_rect1->Render(hdc);
	_rect2->Render(hdc);
	//Rectangle(hdc, 150, 150, 300, 300); // ȸ�� �Ұ��� 

	//SelectObject(hdc, _pens[2]);
	//SelectObject(hdc, _brushes[0]);
	_circle1->Render(hdc);
	_circle2->Render(hdc);
	//Ellipse(hdc, 50, 50, 150, 150); -> ���� �����̴� �� �����ϱ� 
	
	//Collider -> �浹ü

	//Win api â�� �ȼ��� �Ǿ�����(int ���̶� ���)-> �������ϸ� int�� �Ǿ��ִ�.
	// Render �ϴ� ������ �� int 
}
