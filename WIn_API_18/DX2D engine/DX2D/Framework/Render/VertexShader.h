#pragma once
class VertexShader :public Shader
{
public:
	VertexShader(wstring file);
	virtual ~VertexShader();

	virtual void CreateBlob(wstring file)override;
	void CreateInputLayOut();
	void CreateVertexShader();

	virtual void Set() override;

private:
	Microsoft::WRL::ComPtr<ID3D11InputLayout> _inputLayout;	
	Microsoft::WRL::ComPtr<ID3D11VertexShader> _vertexShader;
};

