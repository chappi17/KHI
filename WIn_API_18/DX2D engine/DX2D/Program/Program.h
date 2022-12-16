#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render();

private:

	shared_ptr<MatrixBuffer> _viewBuffer;
	shared_ptr<MatrixBuffer> _projectBuffer;


	unordered_map<string, shared_ptr<Scene>> _scenes;
	shared_ptr<Scene> _curscene;

};

