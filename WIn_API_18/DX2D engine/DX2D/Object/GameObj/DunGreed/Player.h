#pragma once
class Player
{
public:
	Player();
	~Player();

	void Update();
	void Render();

	void Move(const Vector2& pos);
	void Fire(const Vector2& mousePos);

private:
	shared_ptr<Quad> _quad;
	shared_ptr<class Gun> _gun;
	
};

