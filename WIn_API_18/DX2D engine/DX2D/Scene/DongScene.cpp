#include "framework.h"
#include "DongScene.h"

DongScene::DongScene()
{
	_player = make_shared<D_Player>();

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

void DongScene::Update()
{
	_player->Update();

	for (auto dong : _dongs)
		dong->Update();

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

	for (auto dong : _dongs)
	{
		if (dong->IsCollisionWithPlayer(_player))
		{
			dong->_isActive = false;
			_player->_isActive = false;
		}
	}

	_check += DELTA_TIME;
}

void DongScene::Render()
{
	_player->Render();

	for (auto dong : _dongs)
		dong->Render();

}
