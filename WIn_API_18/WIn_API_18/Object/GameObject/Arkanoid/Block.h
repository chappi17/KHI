#pragma once
class Block
{
public:
	Block();
	~Block();

	void Update();
	void Render(HDC hdc);
	void SetPos(const Vector2& pos) { _rectcol->SetCenter(pos); }
	const Vector2& GetBlockSize() { return _rectcol->GetSize(); }

	bool _isActive = false;

private:

	shared_ptr<RectCollider> _rectcol;
};

