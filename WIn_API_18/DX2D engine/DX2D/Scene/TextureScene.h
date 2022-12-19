#pragma once
class TextureScene : public Scene
{
public:
	TextureScene();
	virtual ~TextureScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	shared_ptr<MatrixBuffer> _worldBuffer;
	shared_ptr<MatrixBuffer> _viewBuffer;
	shared_ptr<MatrixBuffer> _projectBuffer;

	XMFLOAT2 _worldPos = { 0,0 }; // 월드 이동
	XMFLOAT2 _cameraPos = { 0,0 }; // 카메라 이동

	float _cameraAngle = 0.0f; // 카메라 회전

	shared_ptr<Quad> _quad1;
	shared_ptr<Quad> _quad2;
};