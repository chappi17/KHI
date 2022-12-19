#pragma once
class RectCollider : public Collider
{
public:
	RectCollider();
	RectCollider(Vector2 size);
	virtual ~RectCollider();

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect) override;

	bool AABB(shared_ptr<RectCollider> rect);
	bool AABB(shared_ptr<CircleCollider> circle);
	bool OBB(shared_ptr<RectCollider> rect);
	
	const Vector2& GetSize() { return _size; }

	float Left()	{ return	_transform->GetWorldPos()._x - halfSize._x; }
	float Right()	{ return	_transform->GetWorldPos()._x + halfSize._x; }
	float Top()		{ return	_transform->GetWorldPos()._y + halfSize._y; }
	float Bottom()	{ return	_transform->GetWorldPos()._y - halfSize._y; }

private:
	void CreateVertices();
	Vector2 _size = Vector2();
	
	Vector2 halfSize = _size * 0.5f;
};

