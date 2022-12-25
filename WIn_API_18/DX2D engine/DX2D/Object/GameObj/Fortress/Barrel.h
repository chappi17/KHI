#pragma once
class Barrel
{
public:
	Barrel();
	~Barrel();

	void Update();
	void Render();

	void FireBullet(const Vector2& mousePos);
	

	void MoveAngle();
		
	Vector2 GetStartPos() { return _startPos; }
	Vector2 GetEndPos() { return _endPos; }

	shared_ptr<Transform> GetTransform() { return _quad->GetTransform();}

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _rectCol;
	shared_ptr<Transform> _barrel;

	Vector2 _endPos;
	Vector2 _startPos;

	UINT _poolCount = 20;
	vector<shared_ptr<class F_bullet>> _bullets;

	
	float _speed = 300.0f;
};

