#include "framework.h"
#include "DongScene.h"

DongScene::DongScene()
{
	_player = make_shared<D_Player>();
	_bg = make_shared<D_BackGround>();
	_bg->Update();

	_player->SetLeftRight(_bg->LeftRight());

	for (int i = 0; i < 50; i++)
	{
		shared_ptr<Dong> dong = make_shared<Dong>();	
		dong->Init();
		_dongs.push_back(dong);
	}
}

DongScene::~DongScene()
{
}

void DongScene::PreRender()
{

}

void DongScene::Update()
{
	_player->Update();

	for (auto dong : _dongs)
		dong->Update();

	for (auto dong : _dongs)
	{
		if (dong->IsCollisionWithPlayer(_player))
		{
			dong->Init();
			--_player->GetHp();
		}
	}

	if (_check > _delay)
	{
		for (auto dong : _dongs)
		{
			if (dong->_isActive == false)
			{
				dong->_isActive = true;
				_check = 0.0f;
				break;
			}
		}
	}

	_check += DELTA_TIME;
	if (_player->GetHp() <= 0)
		_player->_isActive = false;
}

void DongScene::Render()
{
	_bg->Render();
	_player->Render();

	for (auto dong : _dongs)
		dong->Render();

	int playerHP = _player->GetHp();
	ImGui::SliderInt("HP", &playerHP, 0, 10);

}