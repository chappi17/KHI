#pragma once
class VertexBuffer
{
public:
	VertexBuffer(void* data, UINT stride, UINT count, UINT offset = 0);
	~VertexBuffer();

	void IASet(int slot);

private:


	void CreateVertexBuffer(void* data);


	
	Microsoft::WRL::ComPtr<ID3D11Buffer> _vertexbuffer;

	UINT _stride;
	UINT _offset;
	UINT _count;

};

