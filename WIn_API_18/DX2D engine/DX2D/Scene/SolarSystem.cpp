#include "framework.h"
#include "SolarSystem.h"

SolarSystem::SolarSystem()
{	

	_sun = make_shared<Planet>("sun.png", Vector2(150,150));
	_earth = make_shared<Planet>("earth.png", Vector2(100, 100));
	_moon = make_shared<Planet>("moon.png", Vector2(50, 50));

	_sunTrans = make_shared<Transform>();
	_earthTrans = make_shared<Transform>();
		
	_earth->SetParent(_sunTrans);
	_earthTrans->SetParent(_sunTrans);
	_earth->Getpos()._x += 250;	
	_earthTrans->Getpos()._x += 250;

	_moon->SetParent(_earthTrans);
	_moon->Getpos()._x += 120;


}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::Update()
{
	if (KEY_PRESS(0x41))
	{
		_sun->Getpos()._x -= 0.5f * DELTA_TIME * 100;
		_sunTrans->Getpos()._x -= 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x44))
	{
		_sun->Getpos()._x += 0.5f * DELTA_TIME * 100;
		_sunTrans->Getpos()._x += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x57))
	{
		_sun->Getpos()._y += 0.5f * DELTA_TIME * 100;
		_sunTrans->Getpos()._y += 0.5f * DELTA_TIME * 100;
	}

	if (KEY_PRESS(0x53))
	{
		_sun->Getpos()._y -= 0.5f * DELTA_TIME * 100;
		_sunTrans->Getpos()._y -= 0.5f * DELTA_TIME * 100;
	}

	_sun->GetAngle() += 0.005f * DELTA_TIME * 100; // ����
	_sunTrans->GetAngle() += 0.001f * DELTA_TIME * 100; // ����
	_earth->GetAngle() += 0.005f * DELTA_TIME * 100; // ����
	_earthTrans->GetAngle() += 0.001f * DELTA_TIME * 100; // ����
	_moon->GetAngle() += 0.005f * DELTA_TIME * 100; // ���� 

	_sun->Getpos() = mousePos;
	_sunTrans->Getpos() = mousePos;
	_sun->Update();
	_earth->Update();
	_moon->Update();

	_sunTrans->Update();
	_earthTrans->Update();
}

void SolarSystem::Render()
{
	_sunTrans->SetWorldBuffer();
	_earthTrans->SetWorldBuffer();

	_sun->Render();
	_earth->Render();
	_moon->Render();
}
