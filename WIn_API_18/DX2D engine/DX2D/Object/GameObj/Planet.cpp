#include "framework.h"
#include "Planet.h"

Planet::Planet(string name, Vector2 size)
{
	wstring path;
	path.assign(name.begin(), name.end());
	_quad = make_shared<Quad>(path, size);
}

Planet::~Planet()
{
}

void Planet::Update()
{
	_quad->Update();
}

void Planet::Render()
{
	_quad->Render();
}

void Planet::SetParent(shared_ptr<Transform> parent)
{
	_quad->GetTransform()->SetParent(parent);
}
