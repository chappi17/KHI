#pragma once
class Dong
{
public:
	Dong();
	~Dong();

	void Update();
	void Render();

	void Init();

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }

	bool IsCollisionWithPlayer(shared_ptr<D_Player> player);

	bool _isActive = true;

private:
	float _speed = 280.0f;

	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _circleCol;
};

