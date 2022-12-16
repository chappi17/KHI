#pragma once
class PixelShader
{
public:
	PixelShader(wstring file); // L �ٿ��� �Ǵ� ���ڿ� 
	~PixelShader();

	void Set();

private:

	void CreateBlob(wstring file);
	void CreatePixelShader();

	Microsoft::WRL::ComPtr<ID3D11PixelShader> _pixelShader;
	Microsoft::WRL::ComPtr<ID3DBlob> _pixelBlob;
	
};

