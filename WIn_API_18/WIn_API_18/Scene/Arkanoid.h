#pragma once
class Arkanoid : public Scene
{
public:
	Arkanoid();
	virtual ~Arkanoid();
	
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Collider> _mainball;
	shared_ptr<Map> _map;	
	shared_ptr<Bar> _bar;
	vector<shared_ptr<Ball>> _ball;
	bool _isActiveMyBall = false;
};

