Texture2D map :register(t0);
SamplerState samp : register(s0);

cbuffer LeftRight : register(b0)
{
	int leftRight;
	int padding[3];
}

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

// SV_TARGET -> 그릴 곳... 우리한테는 후면버퍼(RTV)
float4 PS(PixelInput input) : SV_TARGET
{
	input.uv.x = abs(input.uv.x - leftRight);
	float4 result = map.Sample(samp, input.uv);

	return result;
}