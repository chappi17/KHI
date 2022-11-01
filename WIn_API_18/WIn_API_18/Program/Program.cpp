#include "framework.h"
#include "Program.h"

#include "../Scene/PaintScene.h"
#include "../Scene/Fortress_scene.h"
#include"../Scene/LineScene.h"

Program::Program()
{
	_scenes["PaintScene"] = make_shared<PaintScene>();
	_scenes["FortressScene"] = make_shared<Fortress_scene>();
	_scenes["LineScene"] = make_shared<LineScene>();

	_targetScene = _scenes["LineScene"];
}

Program::~Program()
{
	_targetScene = nullptr;
}

void Program::Update()
{
	_targetScene->Update();
}

void Program::Reader(HDC hdc)
{
	_targetScene->Render(hdc);

}
