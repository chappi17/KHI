#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_rect = make_shared<RectCollider>(Vector2(100.0f,100.0f ));
	_rect->GetTransform()->Getpos() = { CENTER_X, CENTER_Y };

	_rect2 = make_shared<RectCollider>(Vector2(100.0f, 100.0f));
	_rect2->GetTransform()->Getpos() = { CENTER_X, CENTER_Y };

	_circle = make_shared<CircleCollider>(50.0f);
	_circle->GetTransform()->Getpos() = { CENTER_X+200, CENTER_Y };
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	
	if (KEY_PRESS('W'))
	{
		_circle->GetTransform()->GetScale().x += 1 * DELTA_TIME;
		_circle->GetTransform()->GetScale().y += 1 * DELTA_TIME;
	}

	if (KEY_PRESS('S'))
	{
		_circle->GetTransform()->GetScale().x -= 1 * DELTA_TIME;
		_circle->GetTransform()->GetScale().y -= 1 * DELTA_TIME;
	}

	if (KEY_PRESS('A'))
	{
		_rect->GetTransform()->GetScale().y += 1 * DELTA_TIME;
	}

	if (KEY_PRESS('D'))
	{
		_rect->GetTransform()->GetScale().y -= 1 * DELTA_TIME;
	}

	if (KEY_PRESS(VK_SPACE))
	{
		_rect->GetTransform()->GetAngle() += 0.005f * DELTA_TIME * 100;
	}


	if (_rect->IsCollision(_circle,true))
	{
		_rect->SetRED();
		_circle->SetRED();
	}
	else
	{
		_rect->SetGREEN();
		_circle->SetGREEN();
	}

	_rect->Update();	
	_circle->Update();
}

void CollisionScene::Render()
{
	ImGui::SliderFloat("PosX", &_rect->GetTransform()->Getpos().x, 0, WIN_WIDTH);
	ImGui::SliderFloat("PosY", &_rect->GetTransform()->Getpos().y, 0, WIN_HEIGHT);

	_rect->Render();	
	_circle->Render();
}
