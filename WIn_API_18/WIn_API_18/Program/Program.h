#pragma once
class Program
{
public:

	Program();
	~Program();

	// ������Ʈ�� ���� �����ϴ°� �߿���
	void Update();
	void Reader(HDC hdc);

private:
	shared_ptr<Scene> _targetScene;
	unordered_map < string, shared_ptr<Scene>> _scenes;

};