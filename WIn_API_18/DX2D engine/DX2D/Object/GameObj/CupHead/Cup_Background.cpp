#include "framework.h"
#include "Cup_Background.h"

Cup_Background::Cup_Background()
{
	wstring path = L"CupHead/BackGround/";
	_mainBg = make_shared<Quad>(path + L"clown_bg_main.png");
	_mainBg->GetTransform()->Getpos() = { CENTER_X,CENTER_Y };

	_track = make_shared<Quad>(path + L"clown_bg_track.png");
	_track->GetTransform()->Getpos() = { CENTER_X,CENTER_Y - 250 };

	_mainBg->Update();
	_track->Update();
}

Cup_Background::~Cup_Background()
{

}

void Cup_Background::Update()
{

}

void Cup_Background::Render()
{
	_mainBg->Render();
	_track->Render();
}

Vector2 Cup_Background::GetSize()
{
	Vector2 result = _mainBg->GetSize();
	return result;
}
