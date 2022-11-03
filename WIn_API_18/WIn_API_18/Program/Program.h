#pragma once
class Program
{
public:

	Program();
	~Program();

	// 업데이트랑 렌더 구분하는거 중요함
	void Update();
	void Reader(HDC hdc);

	static HDC _backBuffer;

private:
	shared_ptr<Scene> _targetScene;
	unordered_map < string, shared_ptr<Scene>> _scenes;
	HBITMAP _hBit;

	// BackBuffer
	// Buffer -> Texture(픽셀의 모음)를 임시적으로 저장하는 공간 
	// 깜빡꺼림 없어짐.
};