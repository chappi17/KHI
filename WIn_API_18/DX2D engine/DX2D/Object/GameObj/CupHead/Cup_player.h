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
	void Shot();
	void SetIdle();

	void Update();
	void Render();
	void PostRender();
	void CreateAction(string state);
	
	void SetText() { _text = "IDLE END!!!"; }

	void SetLeft();
	void SetRight();

	shared_ptr<Transform> GetTransform() { return _transform; }
	
	int isActive = false;

private:
	State _state = State::IDLE;

	shared_ptr<Transform> _transform;
	shared_ptr<Transform> _firepos;
	vector <shared_ptr<Sprite>> _sprites;
	shared_ptr<Collider> _collider;
	vector <shared_ptr<Action>> _actions;

	vector <shared_ptr<Cup_bullet>> _bullets;

	int _leftRight = 0;
	float _speed = 100.0f;
	string _text = "Hello World!";
};

