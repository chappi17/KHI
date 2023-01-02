#pragma once
class Cup_Background
{
public:
	Cup_Background();
	~Cup_Background();

	void Update();
	void Render();


private:
	shared_ptr<Quad> _mainBg;
	shared_ptr<Quad> _track;
};

