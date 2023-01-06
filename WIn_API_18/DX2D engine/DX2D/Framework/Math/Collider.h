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

	virtual void Update();
	virtual void Render();

	void SetRED();
	void SetGREEN();

	shared_ptr<Transform> GetTransform() { return _transform; }

	virtual bool IsCollision(shared_ptr<Collider> col, bool isObb = true);

	virtual bool IsCollision(Vector2 pos) abstract;
	virtual bool IsCollision(shared_ptr<RectCollider> rect) abstract;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle) abstract;

	virtual bool OBB(shared_ptr<RectCollider> rect) abstract;
	virtual bool OBB(shared_ptr<CircleCollider> circle) abstract;
	

	ColliderType GetType() { return _type; }

	bool isActive = true;
	static bool _isDebug;

	
protected:
	virtual void CreateData();

	ColliderType _type = ColliderType::NONE;

	vector<Vertex_Bagic> _vertices;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;
	
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<Transform> _transform;
};

