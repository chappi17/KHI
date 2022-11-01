#pragma once
class Line
{
public:
	struct Result
	{
		bool collision = false;
		Vector2 conflict = Vector2();
	};

	Line();
	Line(Vector2 start, Vector2 end);

	~Line();

	void Update();
	void Render(HDC hdc);

	void SetRED() { _curPen = _pens[0]; }
	void SetGREEN() { _curPen = _pens[1]; }

	Result IsCollision(shared_ptr<Line> other);

	Vector2 _startPos;
	Vector2 _endPos;
private:
	HPEN _pens[2];
	HPEN _curPen;
};

