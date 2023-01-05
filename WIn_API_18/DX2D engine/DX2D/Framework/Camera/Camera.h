#pragma once
class Camera
{
public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new Camera();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Camera* Getinstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	void Update();
	void PostRender();

	void ShakeStart(float magnitude, float duration, float reduceDamping = 1.0f);

	void SetViewPort(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);
	void SetProjectionBuffer(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);
	void SetCameraWorldBuffer() { _transform->SetWorldBuffer(1); }
	void SetUICameraBuffer() { _uicameraBuffer->SetVSBuffer(1); }

	void SetTarget(shared_ptr<Transform> target) { _target = target; }
	void SetLeftBottom(Vector2 value) { _leftBottom = value; }
	void SetRightTop(Vector2 value) { _rightTop = value; }
	void SetOffSet(Vector2 value) { _offset = value; }

	Vector2 GetWorldMousePos();

private:
	void Shake();
	void FreeMode();
	void FollowMode();

	Camera();
	~Camera();

	shared_ptr<Transform> _transform; // viewvbuffer 가 되는 것 
	shared_ptr<Transform> _moveTransform;

	shared_ptr<MatrixBuffer> _projectionBuffer;
	shared_ptr<MatrixBuffer> _uicameraBuffer;

	float _speed = 100.0f;

	shared_ptr<Transform> _target= nullptr;
	Vector2 _offset; // offset -> 편차

	Vector2 _leftBottom = { 0.0f, 0.0f };
	Vector2 _rightTop = { 0.0f, 0.0f };


	// 화면 흔들림
	float _duration = 0.0f;
	float _reduceDamping = 0.0f;
	float _magnitude = 0.0f;

	Vector2 _originPos = { 0.0f,0.0f };

	static Camera* _instance;
};

