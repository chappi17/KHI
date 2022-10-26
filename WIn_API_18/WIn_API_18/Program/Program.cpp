#include "framework.h"
#include "Program.h"
#include "../Scene/PaintScene.h"

Program::Program()
{
	_scenes["PaintScene"] = make_shared<PaintScene>();

	_targetScene = _scenes["PaintScene"];
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
