#pragma once
class CircleCollider;


class RectCollider : public Collider
{
public:

	struct OBB_Info
	{
		Vector2 position;
		Vector2 direction[2];
		float length[2];
	};

	RectCollider();
	RectCollider(Vector2 size);
	virtual ~RectCollider();

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect) override;	

	virtual bool OBB(shared_ptr<CircleCollider> circle)override;
	virtual bool OBB(shared_ptr<RectCollider> rect) override;

	Vector2 LeftTop();
	Vector2 RightBottom();

	OBB_Info GetObb();

	const Vector2& GetSize() { return _size; }
	Vector2 GetWorldSize();
	Vector2 HalfSize() { return _size * 0.5f; }

	float SeparateAxis(Vector2 separate, Vector2 e1, Vector2 e2);	

private:
	void CreateVertices();
	Vector2 _size = Vector2();

};

