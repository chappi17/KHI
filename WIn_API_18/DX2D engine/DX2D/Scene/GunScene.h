#pragma once
class GunScene :public Scene
{
public:
	GunScene();
	virtual ~GunScene();	

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Player> _player;
	shared_ptr<RectCollider> _target;
};