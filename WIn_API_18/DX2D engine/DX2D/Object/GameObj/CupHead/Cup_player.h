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

	void Fire();
	
	int LR_state = 0;

private:
	State _state = State::IDLE;

	shared_ptr<Transform> _transform;
	vector <shared_ptr<Sprite>> _sprites;
	shared_ptr<Collider> _collider;
	vector <shared_ptr<Action>> _actions;

	UINT _poolCount = 20;
	shared_ptr<Transform> _muzzle;
	vector<shared_ptr<Cup_bullet>> _bullets;
	shared_ptr<Cup_bullet> _bullet;

	int _leftRight = 0;
	float _speed = 100.0f;
	string _text = "Hello World!";
};

