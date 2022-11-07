#pragma once
class RectCollider;
class CircleCollider;

class Collider 
{
public:
	enum class ColliderType
	{
		NONE,
		CIRCLE,
		RECT
	};

	Collider();
	~Collider();
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	void SetRED();
	void SetGREEN();

	virtual bool IsCollision(Vector2 pos) abstract;
	virtual bool IsCollision(shared_ptr<Collider> col);
	virtual bool IsCollision(shared_ptr<class RectCollider> other)abstract ;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other)abstract;

	const Vector2& GetCenter() { return _center; }
	void SetCenter(const Vector2& center) { _center = center; }

	ColliderType GetType() { return _type;}
	Vector2 _center = Vector2(0, 0);

protected:
	HPEN _curPen;
	HPEN _pens[2];
	

	ColliderType _type = ColliderType::NONE;
};

