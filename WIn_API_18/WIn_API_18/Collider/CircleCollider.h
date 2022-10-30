#pragma once
class RectCollider;

class CircleCollider : public Collider, public enable_shared_from_this<CircleCollider>
{
public:
	CircleCollider();
	CircleCollider(Vector2 center, float radius);
	virtual ~CircleCollider();

	virtual void Update();
	virtual void Render(HDC hdc);
	
	const float& GetRadius() { return _radius; }	
	void SectRadius(const float& value) { _radius = value; }

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect) override;

private:
	float _radius = 0.0f;
};

