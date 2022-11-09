#pragma once
class MazeBlock
{
public:
	enum class BlockType
	{
		ABLE,
		DISABLE,
		END,
		PLAYER,
		FOOTPRINT,
		NONE
	};

	MazeBlock();
	~MazeBlock();

	void Update();
	void Render(HDC hdc);

	BlockType& Type() { return _type; }
	void SetCenter(Vector2 pos) { _rect->SetCenter(pos); }

private:
	BlockType _type = BlockType::NONE;
	vector<HBRUSH> _brushes;
	shared_ptr<RectCollider> _rect;
};

