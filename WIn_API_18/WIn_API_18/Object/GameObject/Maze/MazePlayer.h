#pragma once
class Maze;

class MazePlayer
{
public:
	MazePlayer(shared_ptr<Maze> maze);
	~MazePlayer();

	void RightHand();
	void Update();
	void SetPos(Vector2 pos) { _pos = pos; }

	const Vector2& GetPos() { return _pos; }
	bool Cango(const Vector2& pos);

private:
	Vector2 _pos = Vector2();
	vector<Vector2> _path;
	Dir _dir = Dir::UP;

	float _time = 0.0f;
	int _pathIndex = 0;

	shared_ptr<Maze> _maze;
};

