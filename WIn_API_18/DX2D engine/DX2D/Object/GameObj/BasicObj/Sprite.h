#pragma once
class Sprite : public Quad
{
public:
	Sprite(wstring file, Vector2 maxFrame);
	Sprite(wstring file, Vector2 maxFrame, Vector2 size);

	virtual void Update() override;
	virtual void Render() override;

	void SetSprite(Vector2 curFrame);
	void SetSprite(const Action::Clip& clip);

private:
	shared_ptr<FrameBuffer> _frameBuffer;

};

