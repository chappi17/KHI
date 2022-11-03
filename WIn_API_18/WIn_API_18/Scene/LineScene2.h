#pragma once
class LineScene2 : public Scene
{
public:
	LineScene2();
	virtual ~LineScene2();

	virtual void Update() override;

	virtual void Render(HDC hdc) override;

private:

	shared_ptr<Line> _line1; // �ٴڿ� ���� 
	shared_ptr<Line> _line2; // ���콺 ������ ������ 
	shared_ptr<Line> _line3; // line1�� ���� line2 �� �׸��� (����,projection)

};

