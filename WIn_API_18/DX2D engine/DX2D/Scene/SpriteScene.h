#pragma once
class SpriteScene : public Scene
{
public:
	SpriteScene();
	virtual ~SpriteScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:

	shared_ptr<Sprite> _sprite;

	int _frameX = 0;
	int _frameY = 0;
};

