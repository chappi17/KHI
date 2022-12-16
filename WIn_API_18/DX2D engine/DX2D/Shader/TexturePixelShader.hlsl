Texture2D map : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	float4 result = map.Sample(samp, input.uv);

	if (result.a < 0.5f && result.a > 0.1f )
	{
		result.r = 1.0f;
		result.g = 1.0f;
		result.b = 1.0f;
		result.a += 0.1f;
	}

	return result;
}