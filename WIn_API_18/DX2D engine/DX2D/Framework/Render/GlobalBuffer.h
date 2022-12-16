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

	// pos, scale, angle �ѰŸ�  ��ķ� �ٲ㼭 -> ContantBuffer�� ��� -> Shader ���� �����ϰ� ���
	// 4 X 4 �� �̷���� ���� 

private:

	Data _data;
};