#pragma once
class Bullet
{
public:

	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 dir);
	void SetPos(Vector2 pos);

	bool IsActive() { return _isActive; }
	void SetActive(bool value) { _isActive = value; }

	shared_ptr<CircleCollider> GetCollider() { return _ball; }

private:
	shared_ptr<CircleCollider> _ball;
	Vector2 _dir = Vector2();

	Vector2 _gravity = Vector2();
	float _speed =10.0f;
	bool _isActive = false;
};

