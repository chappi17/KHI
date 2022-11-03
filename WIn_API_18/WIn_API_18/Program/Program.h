#pragma once
class Program
{
public:

	Program();
	~Program();

	// ������Ʈ�� ���� �����ϴ°� �߿���
	void Update();
	void Reader(HDC hdc);

	static HDC _backBuffer;

private:
	shared_ptr<Scene> _targetScene;
	unordered_map < string, shared_ptr<Scene>> _scenes;
	HBITMAP _hBit;

	// BackBuffer
	// Buffer -> Texture(�ȼ��� ����)�� �ӽ������� �����ϴ� ���� 
	// �������� ������.
};