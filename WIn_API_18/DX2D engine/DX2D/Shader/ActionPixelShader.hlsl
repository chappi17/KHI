cbuffer MaxFrame : register(b0)
{
	float2 startPos;
	float2 imageSize; // 이미지 사이즈
	float2 size;
	int leftRight;
	int padding;
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
	spriteUV.x = abs(input.uv.x - leftRight) * (size.x / imageSize.x) + (startPos.x / imageSize.x);
	spriteUV.y = input.uv.y * (size.y / imageSize.y) + (startPos.y / imageSize.y);
	float4 result = map.Sample(samp, spriteUV);

	return result;
}