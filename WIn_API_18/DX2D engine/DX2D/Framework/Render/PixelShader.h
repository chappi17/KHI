#pragma once
class PixelShader :public Shader
{
public:
	PixelShader(wstring file); // L 붙여야 되는 문자열 
	virtual ~PixelShader();

	virtual void Set()override;

private:
	virtual void CreateBlob(wstring file)override;
	void CreatePixelShader();

	Microsoft::WRL::ComPtr<ID3D11PixelShader> _pixelShader;	
};

