#pragma once
class CircleCollider;

class RectCollider : public Collider
{
public:
	RectCollider();
	RectCollider(Vector2 center, Vector2 size);
	virtual ~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc)override;

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle)override;
	virtual bool IsCollision(shared_ptr<RectCollider> other)override ;

	Vector2 LeftTop();
	Vector2 RightBottom();

private:
	Vector2 _size = Vector2();

};

