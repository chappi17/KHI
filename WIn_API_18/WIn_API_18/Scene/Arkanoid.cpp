#include "framework.h"
#include "Arkanoid.h"

Arkanoid::Arkanoid()
{
	_map = make_shared<Map>();
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
	_map->Update();
}

void Arkanoid::Render(HDC hdc)
{
	_map->Render(hdc);
}
