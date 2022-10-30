//#pragma once
//class Collider : public enable_shared_from_this<Collider>
//{
//public:
//	Collider();
//	~Collider();
//	virtual void Update() abstract;
//	virtual void Render(HDC hdc) abstract;
//
//	void SetRED();
//	void SetGREEN();
//
//	virtual bool IsCollision(Vector2 pos);
//	virtual bool IsCollision(shared_ptr<CircleCollider> other);
//	virtual bool IsCollision(shared_ptr<RectCollider> rect);
//
//	const Vector2& GetCenter() { return _center; }
//
//protected:
//	HPEN _curPen;
//	HPEN _pens[2];
//
//	Vector2 _center = Vector2(0, 0);
//};
//
