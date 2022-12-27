cbuffer MaxFrame : register(b1)
{
	float2 maxFrame;
	float2 curFrame;
}

cbuffer LeftRight : register(b0)
{
	int leftRight;
	int padding[3];
}

Texture2D map : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	float2 spriteUV;
	spriteUV.x = abs(input.uv.x - leftRight) / maxFrame.x + curFrame.x / maxFrame.x;
	spriteUV.y = input.uv.y / maxFrame.y + curFrame.y / maxFrame.y;
	float4 result = map.Sample(samp, spriteUV);

	return result;
}