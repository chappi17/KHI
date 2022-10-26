#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void OnEnable() {}
	virtual void Disable() {}

	virtual void Update() abstract ;
	virtual void Render(HDC hdc) abstract;

};

