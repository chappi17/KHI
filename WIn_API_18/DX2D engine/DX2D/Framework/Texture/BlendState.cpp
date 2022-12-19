#include "framework.h"
#include "BlendState.h"

BlendState::BlendState()
	: _desc({})
{
	_desc.AlphaToCoverageEnable = false;
	_desc.IndependentBlendEnable = false;

	_desc.RenderTarget[0].BlendEnable = true; // 알파연산하겠다.
	_desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA; // 렌더타켓에 그릴 이미지가 가지는 불투명도를 곱하겠다.
	_desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE; // 뒷배경에다 출력할 이미지 alpha의 역수를 곱하겠다.
	_desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD; // 알파연산을 덧셈으로 하겠다.

	_desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
	_desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	_desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

	_desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	Change();
}

BlendState::~BlendState()
{
}

void BlendState::SetState()
{
	float blendFactor[] = { 0,0,0,0 };
	DC->OMSetBlendState(_state.Get(), blendFactor, 0xffffffff);
}

void BlendState::Alpha()
{
	_desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	Change();
}

void BlendState::Additive()
{
	_desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
	Change();
}

void BlendState::Change()
{
	DEVICE->CreateBlendState(&_desc, _state.ReleaseAndGetAddressOf());
}
