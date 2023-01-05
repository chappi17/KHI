#pragma once
class Cup_boss
{
public:
	enum State
	{
		IDLE = 0,
	};

	Cup_boss();
	~Cup_boss();

	UINT& GetHp() { return _hp; }

	void SetIdle();

	void Update();
	void Render();
	void PostRender();
	void CreateAction(string state);

	shared_ptr<Collider> GetCollider() { return _collider; }

	bool isActive = false;

private:
	State _state = State::IDLE;

	shared_ptr<Transform> _transform;
	vector <shared_ptr<Sprite>> _sprites;
	vector <shared_ptr<Action>> _actions;
	shared_ptr<Collider> _collider;

	UINT _hp = 10;


	float _speed = 100.0f;
};

