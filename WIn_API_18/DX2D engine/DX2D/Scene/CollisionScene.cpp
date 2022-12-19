#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_rect = make_shared<RectCollider>(Vector2(100.0f,100.0f ));
	_rect->GetTransform()->Getpos() = { CENTER_X, CENTER_Y };

	_rect2 = make_shared<RectCollider>(Vector2(100.0f, 100.0f));
	_rect2->GetTransform()->Getpos() = { CENTER_X+ 200, CENTER_Y};

	_circle = make_shared<CircleCollider>(50.0f);
	_circle->GetTransform()->Getpos() = { CENTER_X+200, CENTER_Y+200 };
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	
	if (_rect->IsCollision(_circle))
		{			
		_circle->SetRED();
		}
	else
		{		
		_circle->SetGREEN();
		}
	
	_rect->Update();
	_circle->Update();
	


//	_circle->Update();
}

void CollisionScene::Render()
{
	ImGui::SliderFloat("PosX", &_rect->GetTransform()->Getpos()._x, 0, WIN_WIDTH);
	ImGui::SliderFloat("PosY", &_rect->GetTransform()->Getpos()._y, 0, WIN_HEIGHT);

	_rect->Render();
	_circle->Render();
//	_circle->Render();
}
