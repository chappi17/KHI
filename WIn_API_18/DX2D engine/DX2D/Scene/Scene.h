#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void PreRender() {};
	virtual void Update() abstract;
	virtual void Render() abstract;
	virtual void PostRender() {};

protected:
	
};