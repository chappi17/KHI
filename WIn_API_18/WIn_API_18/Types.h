#pragma once

#define RED		RGB(255,0,0)
#define GREEN	RGB(0,255,0)
#define BLUE	RGB(0,0,255)

struct Vector2 // 2Â÷¿ø 
{
	Vector2() {}
	Vector2(float x, float y) : _x(x), _y(y) {}

	float _x= 0.0f;
	float _y = 0.0f;
};