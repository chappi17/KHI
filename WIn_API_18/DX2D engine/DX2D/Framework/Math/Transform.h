#pragma once

class MatrixBuffer;

// SRT 매트릭스 관리
class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void SetWorldBuffer();

	Vector2& GetScale() { return _scale; }
	Vector2& Getpos() { return _pos; }
	Vector2 GetWorldPos();


	float& GetAngle() { return _angle; }

	void SetParent(shared_ptr<Transform> parent) { _parent = parent->GetMatrix(); }
	XMMATRIX* GetMatrix() { return &_srtMatrix; }


private:
	Vector2 _scale = { 1.0f,1.0f };
	float _angle = 0.0f;
	Vector2 _pos = { 0.0f,0.0f };

	XMMATRIX _srtMatrix = XMMatrixIdentity();
	shared_ptr<MatrixBuffer> _worldBuffer;

	Float4x4 _Worldpos;
	XMMATRIX* _parent = nullptr;
};

