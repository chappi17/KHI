#pragma once
class LineScene2 : public Scene
{
public:
	LineScene2();
	virtual ~LineScene2();

	virtual void Update() override;

	virtual void Render(HDC hdc) override;

private:

	shared_ptr<Line> _line1; // 바닥에 고정 
	shared_ptr<Line> _line2; // 마우스 포스로 움직임 
	shared_ptr<Line> _line3; // line1에 대한 line2 의 그림자 (투영,projection)

};

