#pragma once

class MatrixBuffer;

// SRT 매트릭스 관리 -> 점 하나를 나타냄 0, 0, 0 상태
class Transform // 점 한개인데, 매트릭스를 가지고 있는 것 
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


	XMMATRIX _srtMatrix = XMMatrixIdentity(); // 위에 있는 스케일, 앵글, 포스 담는 곳 
	shared_ptr<MatrixBuffer> _worldbuffer; // 0,0,0 이다. 

	XMMATRIX* _parent = nullptr;
};

