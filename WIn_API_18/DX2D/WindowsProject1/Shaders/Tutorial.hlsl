Texture2D map : register(t0);
SamplerState samp :register(s0);


struct VertexInput
{
	float4 pos : POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

// VertexShader
PixelInput VS(VertexInput input)
{
	PixelInput result;
	result.pos = input.pos;
	result.color = input.color;	
	result.uv = input.uv;

	return result;
}

// SV_TARGET -> �׸���.... �츮���״� �ĸ���� (RTV)
float PS(VertexInput input) : SV_TARGET
{
	return map.Sample(samp, input.uv);
}