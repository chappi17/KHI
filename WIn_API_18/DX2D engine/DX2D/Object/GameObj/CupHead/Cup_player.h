#pragma once
class Cup_player
{
public:
	enum State
	{
		IDLE = 0,
		RUN =1,		
		SHOT = 2
	};

	Cup_player();
	~Cup_player();

	void Input();

	void Update();
	void Render();
	void PostRender();
	void CreateAction(string state);
	
	void SetText() { _text = "IDLE END!!!"; }

	void SetLeft();
	void SetRight();

private:
	State _state = State::IDLE;
	State _state3 = State::SHOT;

	shared_ptr<Transform> _transform;
	vector <shared_ptr<Sprite>> _sprites;
	shared_ptr<Collider> _collider;
	vector <shared_ptr<Action>> _actions;	

	int _leftRight = 0;
	float _speed = 100.0f;
	string _text = "Hello World!";
};

