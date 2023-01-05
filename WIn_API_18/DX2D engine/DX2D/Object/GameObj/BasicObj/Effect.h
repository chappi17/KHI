#pragma once
class Effect
{
public:
	Effect(wstring file,Vector2 maxFrame, Vector2 size, float speed = 0.1f, Action:: Type type = Action::Type::END);
	~Effect();

	void Update();
	void Render();
	void PostRender();

	void CreateAction(wstring file, Vector2 maxFrame, float speed = 0.1f, Action::Type type =Action ::Type:: END );

	void Play(Vector2 pos);
	void Play_1();
	void End();

	bool isActive;
private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
};

