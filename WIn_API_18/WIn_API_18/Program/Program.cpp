#include "framework.h"
#include "Program.h"

#include "../Scene/PaintScene.h"
#include "../Scene/Fortress_scene.h"
#include"../Scene/LineScene.h"
#include"../Scene/LineScene2.h"
#include"../Scene/Arkanoid.h"

Program::Program()
{
	_scenes["PaintScene"] = make_shared<PaintScene>();
	_scenes["FortressScene"] = make_shared<Fortress_scene>();
	_scenes["LineScene"] = make_shared<LineScene>();
	_scenes["LineScene2"] = make_shared<LineScene2>();
//	_scenes["Arkanoid"] = make_shared<Arkanoid>();

	_targetScene = _scenes["LineScene2"];
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
