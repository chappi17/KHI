#pragma once
class RectCollider;

class CircleCollider : public Collider
{
public:
	CircleCollider();
	CircleCollider(float radius);
	~CircleCollider();

	const float& GetRadius() { return _radius * _transform->GetScale()._x; }
	void SetRadius(const float& value) { _radius = value; }

	virtual bool IsCollision(Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect) override;

	float GetWorldRadius();

private:
	void CreateVertices();

	int	dot;

	float _radius = 0.0f;
};

