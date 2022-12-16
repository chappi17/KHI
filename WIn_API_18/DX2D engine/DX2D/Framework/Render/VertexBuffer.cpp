#include "framework.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(void* data, UINT stride, UINT count, UINT offset)
    : _stride(stride)
    , _count(count)
    ,_offset(offset)
{
    CreateVertexBuffer(data);
}

VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::IASet(int slot)
{
    DC->IASetVertexBuffers(slot, 1, _vertexbuffer.GetAddressOf(),
        &_stride, &_offset);
}


    
    //_stride = sizeof(Vertex_UV);
    //_offset = 0;

     /*  Vertex vertices[] =
      {
          XMFLOAT3(-0.5f,0.5f,0.0f),
          XMFLOAT3(0.5f,-0.5f,0.0f),
          XMFLOAT3(-0.5f,-0.5f,0.0f),

          XMFLOAT3(0.5f,0.5f,0.0f),
          XMFLOAT3(0.5f,-0.5f,0.0f),
          XMFLOAT3(-0.5f,0.5f,0.0f),
      };*/



      // Texture �غ��ϰ�, Shader ���� �ѱ�� �۾�

           // DX���� View�� ������

void VertexBuffer::CreateVertexBuffer(void* data)
{
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = _stride * _count;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = data;

    DEVICE->CreateBuffer(&bd, &initData, _vertexbuffer.GetAddressOf());
}
