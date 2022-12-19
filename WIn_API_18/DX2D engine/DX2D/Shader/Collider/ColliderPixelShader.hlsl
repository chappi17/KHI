
cbuffer ColorBuffer : register(b0)
{
	float4 color;
}

struct PixelInput
{
	float4 pos : SV_POSITION;
};

// SV_TARGET -> 그릴 곳... 우리한테는 후면버퍼(RTV)
float4 PS(PixelInput input) : SV_TARGET
{
	return color;
}