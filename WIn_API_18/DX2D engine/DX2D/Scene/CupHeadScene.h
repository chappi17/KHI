#pragma once
class CupHeadScene : public Scene
{
public:
	CupHeadScene();
	virtual ~CupHeadScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<Cup_player> _player;
	shared_ptr<Cup_Background> _bg;
	shared_ptr<Cup_bullet> _bullet;

};