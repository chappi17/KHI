#pragma once

class MatrixBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMMATRIX _matrix = XMMatrixIdentity();
	};

	MatrixBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
	}

	void SetData(XMMATRIX value)
	{
		_data._matrix = XMMatrixTranspose(value);
	}

	virtual ~MatrixBuffer() {}

private:

	Data _data;
};

class ColorBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT4 color;
	};

	ColorBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
		_data.color = { 255,0.0f,0.0f, 1.0f }; // 
	}

	Data _data;
};

class FrameBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 maxFrame;
		XMFLOAT2 curFrame;
	};

	FrameBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
		_data.maxFrame = { 1,1 };
		_data.curFrame = { 1,1 };
	}

	Data _data;
};