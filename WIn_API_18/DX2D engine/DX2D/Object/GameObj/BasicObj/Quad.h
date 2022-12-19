#pragma once
class Quad
{
public:
	Quad(wstring file);
	Quad(wstring file, Vector2 size);
	~Quad();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _transform; }

private:
	void CreateVertricesAndIndices();

	// Mesh... 정점들의 집합
	vector<Vertex_UV> _vertices;
	vector<UINT> _indices;

	shared_ptr<VertexBuffer> _vBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	// -------------------------------

	Vector2 _size = { 1.0f,1.0f };
	shared_ptr<Transform> _transform;

	// Meterial... 재질
	shared_ptr<SRV> _srv;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;
	// ----------------------------
};

