#pragma once
class FortressScene : public Scene
{
public:
	FortressScene();
	~FortressScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	
private:
	shared_ptr<Cannon> _player;

};

