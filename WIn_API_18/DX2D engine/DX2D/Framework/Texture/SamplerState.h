#pragma once
class SamplerState
{
public:
	SamplerState();
	~SamplerState();

	void Set(int slot);

private:
	Microsoft::WRL::ComPtr<ID3D11SamplerState> _samplerState;
};

