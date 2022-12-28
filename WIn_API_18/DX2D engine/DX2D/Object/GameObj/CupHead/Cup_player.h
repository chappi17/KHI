#pragma once
class Cup_player
{
public:
	enum State
	{
		IDLE
	};

	Cup_player();
	~Cup_player();

	void Input();

	void Update();
	void Render();
	void PostRender();
	void CreateAction();
	
	void SetText() { _text = "IDLE END!!!"; }

private:
	State _state;

	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _collider;
	shared_ptr<Action> _action;

	float _speed = 30.0f;
	string _text = "Hello World!";

};

