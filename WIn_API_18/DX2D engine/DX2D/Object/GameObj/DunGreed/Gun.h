#pragma once
class Gun
{
public:
	Gun();
	~Gun();

	void Update();
	void Render();

	void FireBullet(const Vector2& mousePos);

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	vector<shared_ptr<class Bullet>> GetBullets() { return _bullets; }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _muzzle;

	UINT _poolCount = 20;
	vector<shared_ptr<class Bullet>> _bullets;
};
