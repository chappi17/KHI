#include "framework.h"
#include "Camera.h"

Camera* Camera::_instance = nullptr;

Camera::Camera()
{
	_transform = make_shared<Transform>();
	_moveTransform = make_shared<Transform>();
	_projectionBuffer = make_shared<MatrixBuffer>();
	_uicameraBuffer = make_shared<MatrixBuffer>();

	SetProjectionBuffer();
}

Camera::~Camera()
{

}

void Camera::Update()
{
	if (_target == nullptr)
		FreeMode();
	else
		FollowMode();

	Shake();

	_transform->Update();
	_moveTransform->Getpos().x = -_transform->Getpos().x;
	_moveTransform->Getpos().y = -_transform->Getpos().y;
}

void Camera::PostRender()
{
	ImGui::Text("Camera Info");
	ImGui::Text("CameraX : %0.1f, CameraY : %0.1f", _moveTransform->Getpos().x, _moveTransform->Getpos().y);
}

void Camera::ShakeStart(float magnitude, float duration, float reduceDamping)
{
	_magnitude = magnitude;
	_duration = duration;
	_reduceDamping = reduceDamping;

	_originPos = _transform->Getpos();
}

void Camera::SetViewPort(UINT width, UINT height)
{
	D3D11_VIEWPORT vp;
	vp.Width = width;
	vp.Height = height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	DC->RSSetViewports(1, &vp);
}

void Camera::SetProjectionBuffer(UINT width, UINT height)
{
	XMMATRIX projectionM = XMMatrixOrthographicOffCenterLH(0.0f, width, 0, height, -1.0f, 1.0f);

	_projectionBuffer->SetData(projectionM);

	_projectionBuffer->SetVSBuffer(2);
}

Vector2 Camera::GetWorldMousePos()
{
	XMMATRIX inverseView = DirectX::XMMatrixInverse(nullptr, *_transform->GetMatrix());

	return Vector2::TransformCoord(mousePos, inverseView);
}

void Camera::Shake()
{
	if(_duration <= 0.0f)
		return;

	_duration -= DELTA_TIME;
	_magnitude -= DELTA_TIME * _reduceDamping;

	if (_magnitude <= 0.0f)
	{
		_magnitude = 0.0f;
		_duration = 0.0f;
	}

	_transform->Getpos().x = _originPos.x + MathUtility::RandomFloat(-_magnitude, _magnitude);
	_transform->Getpos().y = _originPos.y + MathUtility::RandomFloat(-_magnitude, _magnitude);

	if (_duration <= 0.0f)
		_transform->Getpos() = _originPos;
}

void Camera::FreeMode()
{
	if (KEY_PRESS(VK_RBUTTON))
	{
		if (KEY_PRESS('W'))
			_transform->Getpos().y -= _speed * DELTA_TIME;
		if (KEY_PRESS('S'))
			_transform->Getpos().y += _speed * DELTA_TIME;
		if (KEY_PRESS('D'))
			_transform->Getpos().x -= _speed * DELTA_TIME;
		if (KEY_PRESS('A'))
			_transform->Getpos().x += _speed * DELTA_TIME;
	}
}

void Camera::FollowMode()
{
	Vector2 targetPos = _target->GetWorldPos() - _offset;

	if (targetPos.x < _leftBottom.x)
		targetPos.x = _leftBottom.x;

	if (targetPos.x > _rightTop.x - WIN_WIDTH)
		targetPos.x = _rightTop.x - WIN_WIDTH;

	if (targetPos.y < _leftBottom.y)
		targetPos.y = _leftBottom.y;

	if (targetPos.y > _rightTop.y - WIN_HEIGHT)
		targetPos.y = _rightTop.y - WIN_HEIGHT;

	_transform->Getpos() = LERP(_transform->Getpos(), targetPos * -1, DELTA_TIME * 5.0f);
}