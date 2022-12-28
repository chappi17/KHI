#pragma once
class DongScene : public Scene
{
public:
	DongScene();
	virtual ~DongScene();

	virtual void PreRender() override;
	virtual void Update() override;
	virtual void Render() override;

private:	

	float _check = 0.0f;
	float _delay = 1.0f;

	shared_ptr<D_BackGround> _bg;
	shared_ptr<D_Player> _player;
	vector<shared_ptr<Dong>> _dongs;

	
};