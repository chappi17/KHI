#pragma once

class MatrixBuffer;

// SRT ��Ʈ���� ���� -> �� �ϳ��� ��Ÿ�� 0, 0, 0 ����
class Transform // �� �Ѱ��ε�, ��Ʈ������ ������ �ִ� �� 
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


	XMMATRIX _srtMatrix = XMMatrixIdentity(); // ���� �ִ� ������, �ޱ�, ���� ��� �� 
	shared_ptr<MatrixBuffer> _worldbuffer; // 0,0,0 �̴�. 

	XMMATRIX* _parent = nullptr;
};

