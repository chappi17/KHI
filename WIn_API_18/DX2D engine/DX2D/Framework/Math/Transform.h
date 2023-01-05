#pragma once

class MatrixBuffer;

class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void SetWorldBuffer(int slot =0);

	Vector2& GetScale();
	Vector2 GetWorldScale();
	Vector2& Getpos() { return _pos; }
	Vector2 GetWorldPos();
	float& GetAngle();
	float GetWorldAngle();

	void SetParent(shared_ptr<Transform> parent) { _parent = parent; }
	XMMATRIX* GetMatrix() { return &_srtMatrix; }

private:
	Vector2 _scale = { 1.0f, 1.0f };
	float _angle = 0.0f;
	Vector2 _pos = { 0.0f, 0.0f };

	XMMATRIX _srtMatrix = XMMatrixIdentity();
	shared_ptr<MatrixBuffer> _worldBuffer;

	shared_ptr<Transform> _parent = nullptr;
};
