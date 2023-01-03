#pragma once

class Cup_bullet
{
public:
	Cup_bullet();
	~Cup_bullet();

	void Update();
	void Render();
	void SetDir(const Vector2& dir) { _dir = dir.Normal(); }
	shared_ptr<Transform> GetTransform() { return _transform; }

	bool _isActive = false;

private:
	shared_ptr<Transform>	_transform;
	shared_ptr <Collider>	_circleCol;

	Vector2		_dir = Vector2();
	float		_speed = 800.0f;
	
};

