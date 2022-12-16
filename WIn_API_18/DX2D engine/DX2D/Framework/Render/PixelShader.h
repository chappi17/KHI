#pragma once
class PixelShader
{
public:
	PixelShader(wstring file); // L 붙여야 되는 문자열 
	~PixelShader();

	void Set();

private:

	void CreateBlob(wstring file);
	void CreatePixelShader();

	Microsoft::WRL::ComPtr<ID3D11PixelShader> _pixelShader;
	Microsoft::WRL::ComPtr<ID3DBlob> _pixelBlob;
	
};

