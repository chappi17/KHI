#pragma once
class CupHeadScene : public Scene
{
public:
	CupHeadScene();
	virtual ~CupHeadScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void CreateAction();

private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;

	int _frameX = 0;
	int _frameY = 0;

	int _leftRight = 0;
};

