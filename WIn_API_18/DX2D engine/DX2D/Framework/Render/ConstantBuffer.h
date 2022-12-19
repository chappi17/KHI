#pragma once
// 상수 버퍼
class ConstantBuffer
{
public:
	ConstantBuffer(void* data, UINT dataSize);
	virtual ~ConstantBuffer();

	void Update();

	void SetVSBuffer(UINT slot);
	void SetPSBuffer(UINT slot);

protected:
	Microsoft::WRL::ComPtr<ID3D11Buffer> _buffer;

	void* _data;
	UINT _dataSize;
};

