#pragma once
class MatrixBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMMATRIX _matrix = XMMatrixIdentity();
	};



	MatrixBuffer()
	:ConstantBuffer(&_data, sizeof(Data))
	{
	}

	void SetData(XMMATRIX value)
	{
		_data._matrix = XMMatrixTranspose(value);
	}

	virtual ~MatrixBuffer() {}

	// pos, scale, angle 한거를  행렬로 바꿔서 -> ContantBuffer에 묶어서 -> Shader 한테 전달하고 계산
	// 4 X 4 로 이루어져 있음 

private:

	Data _data;
};