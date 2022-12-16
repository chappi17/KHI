#pragma once
class VertexShader
{
public:
	VertexShader(wstring file);
	~VertexShader();

	void CreateBlob(wstring file);
	void CreateInputLayOut();
	void CreateVertexShader();

	void Set();

private:
	Microsoft::WRL::ComPtr<ID3D11InputLayout> _inputLayOut;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> _vertexshader;
	Microsoft::WRL::ComPtr<ID3DBlob> _vertexBlob;
};
