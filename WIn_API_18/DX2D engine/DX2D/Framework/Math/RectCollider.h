#pragma once
class CircleCollider;


class RectCollider : public Collider, public enable_shared_from_this<RectCollider>
{
public:
	RectCollider();
	RectCollider(Vector2 size);
	virtual ~RectCollider();

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect) override;

	bool AABB(shared_ptr<RectCollider> rect);	
	bool OBB(shared_ptr<RectCollider> rect);
	
	Vector2 LeftTop();
	Vector2 RightBottom();

	const Vector2& GetSize() { return _size; }
	Vector2 GetWorldSize();
	Vector2 HalfSize() { return _size * 0.5f; }

	

private:
	void CreateVertices();
	Vector2 _size = Vector2();

};

