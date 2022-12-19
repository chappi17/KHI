#include "framework.h"
#include "PixelShader.h"

PixelShader::PixelShader(wstring file)
{
	CreateBlob(file);
	CreatePixelShader();
}

PixelShader::~PixelShader()
{
}

void PixelShader::Set()
{
	DC->PSSetShader(_pixelShader.Get(), nullptr, 0);
}

void PixelShader::CreateBlob(wstring file)
{
	wstring path = L"Shader/";
	path += file;
	path += L".hlsl";

	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

	D3DCompileFromFile(path.c_str(), nullptr, nullptr,
		"PS", "ps_5_0", flags, 0, _pixelBlob.GetAddressOf(), nullptr);
}

void PixelShader::CreatePixelShader()
{
	DEVICE->CreatePixelShader(_pixelBlob->GetBufferPointer(), _pixelBlob->GetBufferSize(), nullptr,
		_pixelShader.GetAddressOf());
}
