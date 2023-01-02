#pragma once
class Sprite : public Quad
{
public:
	Sprite(wstring file, Vector2 size);
	Sprite(wstring file, Vector2 maxFrame, Vector2 size);

	virtual void Update() override;
	virtual void Render() override;

	void SetSpriteByFrame(Vector2 curFrame);
	void SetSpriteByAction(const Action::Clip& clip);
	void SetLeft() { _actionBuffer->_data.leftRight = 1; }
	void SetRight() { _actionBuffer->_data.leftRight = 0; }

private:	
	shared_ptr<ActionBuffer> _actionBuffer;

	Vector2 _maxFrame = { 1.0f, 1.0f };
};