#pragma once

class Cup_bullet
{
public:
	Cup_bullet();
	~Cup_bullet();

	void CreateAction();
	
	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }
	void SetDirection(Vector2 dir);
	bool _isActive = false;

private:

	double		_lastTime = 0.0;
	double		_curTime = 0.0;
	double		_delay = 1.5;


	shared_ptr<Transform>	_transform;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
	shared_ptr <Collider>	_collider;

	Vector2 _direction = { 0,0 };
	float		_speed = 800.0f;
	
};

