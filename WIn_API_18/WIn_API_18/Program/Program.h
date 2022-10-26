#pragma once
class Program
{
public:

	Program();
	~Program();

	// 업데이트랑 렌더 구분하는거 중요함
	void Update();
	void Reader(HDC hdc);

private:
	shared_ptr<Scene> _targetScene;
	unordered_map < string, shared_ptr<Scene>> _scenes;

};