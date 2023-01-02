Texture2D map :register(t0);
SamplerState samp : register(s0);


cbuffer LeftRight : register(b0)
{
	int leftRight;
	int padding1[3];
}

cbuffer Filter : register(b1)
{
	int selected;
	int value1;
	int value2;
	int value3;
}

cbuffer ImageSize : register(b2)
{
	float2 imageSize;
	float2 padding2;
}

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 Mosaic(float2 uv) // 픽셀 나눠서 덮어버린다..?
{
	float x = floor(uv.x * value1);
	float y = floor(uv.y * value1);

	float2 temp;
	temp.x = x / value1;
	temp.y = y / value1;

	return map.Sample(samp, temp);
}

float4 Blur(float2 uv)
{
	float4 result = 0;

	for (int i = 0; i < value2; i++)
	{
		float divX = (i + 1) / imageSize.x;
		float divY = (i + 1) / imageSize.y;

		result += map.Sample(samp, float2(uv.x + divX, uv.y));
		result += map.Sample(samp, float2(uv.x - divX, uv.y));
		result += map.Sample(samp, float2(uv.x, uv.y + divY));
		result += map.Sample(samp, float2(uv.x, uv.y - divY));
	}

	result /= 4 * value2;

	return result;
}

// SV_TARGET -> 그릴 곳... 우리한테는 후면버퍼(RTV)
float4 PS(PixelInput input) : SV_TARGET
{
	[branch]
	if (selected == 0)
		return map.Sample(samp, input.uv);
	else if (selected == 1)
		return Mosaic(input.uv);
	else if (selected == 2)
		return Blur(input.uv);

	return map.Sample(samp, input.uv);
}