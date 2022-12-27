#include "framework.h"
#include "VertexShader.h"

VertexShader::VertexShader(wstring file)
{
    CreateBlob(file);
    CreateInputLayOut();
    CreateVertexShader();
}

VertexShader::~VertexShader()
{
}

void VertexShader::CreateBlob(wstring file)
{
    wstring path = L"Shader/";
    path += file;
    path += L".hlsl";
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS || D3DCOMPILE_DEBUG;
    D3DCompileFromFile(path.c_str(), nullptr, nullptr,
        "VS", "vs_5_0", flags, 0, _blob.GetAddressOf(), nullptr);
}

void VertexShader::CreateInputLayOut()
{
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        {
            "POSITION",0, DXGI_FORMAT_R32G32B32_FLOAT,0,0,
            D3D11_INPUT_PER_VERTEX_DATA,0
        },
        {
            "UV",0, DXGI_FORMAT_R32G32_FLOAT,0,12,
            D3D11_INPUT_PER_VERTEX_DATA,0
        }
    };

    UINT layoutSize = ARRAYSIZE(layout);

    DEVICE->CreateInputLayout(layout, layoutSize, _blob->GetBufferPointer(),
        _blob->GetBufferSize(), _inputLayout.GetAddressOf());
}

void VertexShader::CreateVertexShader()
{
    DEVICE->CreateVertexShader(_blob->GetBufferPointer(), _blob->GetBufferSize(), nullptr,
        _vertexShader.GetAddressOf());
}

void VertexShader::Set()
{
    DC->IASetInputLayout(_inputLayout.Get());
    DC->VSSetShader(_vertexShader.Get(), nullptr, 0);
}
