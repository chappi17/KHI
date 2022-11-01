#pragma once
class Fortress_scene :public Scene
{
public:
	Fortress_scene();
	virtual ~Fortress_scene();
	
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Cannon> _cannon;
	shared_ptr<Cannon> _cannon2;
	shared_ptr<Cannon> _bullet;
	shared_ptr<Cannon> _enemy_body;

	float _angle = 0.0f;

};

