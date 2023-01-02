#pragma once
class Quad
{
public:
	Quad(wstring file);
	Quad(wstring file, Vector2 size);
	virtual ~Quad();

	virtual void Update();
	virtual void Render();

	void SetVertexShader(shared_ptr<VertexShader> vs) { _vs = vs; }
	void SetPixelShader(shared_ptr<PixelShader> ps) { _ps = ps; }

	Vector2 GetSize() { return _size; }

	void SetLeftRight_leftRightBuffer(int leftRight);

	shared_ptr<Transform> GetTransform() { return _transform; }
	


protected:
	void CreateVertricesAndIndices();
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

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

	shared_ptr<LeftRightBuffer> _leftRightBuffer;

	// ----------------------------
};