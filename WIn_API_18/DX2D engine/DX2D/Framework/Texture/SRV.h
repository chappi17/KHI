#pragma once
class SRV
{
public:
	SRV(wstring file);
	~SRV();

	void Set(int slot);
	const Vector2& GetSize() { return _size; }
private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> _shaderResourceView;
	Vector2 _size;
};

