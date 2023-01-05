#pragma once
class Cup_Background
{
public:
	Cup_Background();
	~Cup_Background();

	void Update();
	void Render();

	Vector2 GetSize();
	Vector2 GetMainPos() { return _mainBg->GetTransform()->GetWorldPos(); }

private:
	shared_ptr<Quad> _mainBg;
	shared_ptr<Quad> _track;
};

