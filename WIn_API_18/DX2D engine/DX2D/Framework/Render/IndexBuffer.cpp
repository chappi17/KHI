#include "framework.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(void* data, UINT count)
{
	D3D11_BUFFER_DESC bd = {};
	// DEFALT 변환 X 
	// DYNAMIC 변환 O
	bd.Usage = D3D11_USAGE_DEFAULT; 
	bd.ByteWidth = sizeof(UINT) * count;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = data;

	// 정점 인덱스를 담는 정점 버퍼 
	DEVICE->CreateBuffer(&bd, &initData, _buffer.GetAddressOf());
	
}

IndexBuffer::~IndexBuffer()
{
}

void IndexBuffer::IASet()
{
	DC->IASetIndexBuffer(_buffer.Get(), DXGI_FORMAT_R32_UINT, 0);
}
