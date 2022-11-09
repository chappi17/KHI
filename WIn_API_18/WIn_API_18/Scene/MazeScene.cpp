#include "framework.h"
#include "MazeScene.h"

MazeScene::MazeScene()
{
	_maze = make_shared<Maze>();
	_player = make_shared<MazePlayer>(_maze);
	_maze->SetPlayer(_player);
}

MazeScene::~MazeScene()
{
}

void MazeScene::Update()
{
	_maze->Update();
	_player->Update();
}

void MazeScene::Render(HDC hdc)
{
	_maze->Render(hdc);
}
