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

class LeftRightBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		int leftRight = 0;
		int padding[3];
	};

	LeftRightBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
		_data.leftRight = 0;
		_data.padding[0] = 0;
		_data.padding[1] = 0;
		_data.padding[2] = 0;
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

class ActionBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 startPos ;
		XMFLOAT2 imageSize ;
		XMFLOAT2 size ;
		int leftRight = 0;
		int padding;
	};

	ActionBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
	
	}

	Data _data;
};

class FilterBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		int selected = 0;
		int value1 = 0;
		int value2 = 0;
		int value3 = 0;
	};

	FilterBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{

	}

	Data _data;
};

class ImageSizeBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 imageSize = { 0.0f,0.0f };
		XMFLOAT2 padding;
	};

	ImageSizeBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{

	}

	Data _data;
};