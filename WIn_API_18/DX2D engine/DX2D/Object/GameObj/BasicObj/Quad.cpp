#include "framework.h"
#include "Quad.h"


Quad::Quad(wstring file)
{
	wstring path = L"Resource/Texture/" + file;
	_srv = make_shared<SRV>(path);

	_srv = SRVManager::GetInstance()->AddSRV(path);
	_size = _srv->GetSize();

	_transform = make_shared<Transform>();

		_ps = make_shared<PixelShader>(L"TexturePixelShader");
}

Quad::Quad(wstring file, Vector2 size)
	: _size(size)
{
	wstring path = L"Resource/Texture/" + file;
	_srv = make_shared<SRV>(path);
	_srv = SRVManager::GetInstance()->AddSRV(path);

	_size = size;
	_transform = make_shared<Transform>();

	CreateVertricesAndIndices();


		_vs = make_shared<VertexShader>(L"TextureVertexShader");
	_ps = make_shared<PixelShader>(L"TexturePixelShader");

}


Quad::~Quad()
{
}


void Quad::Update()
{
	_transform->Update();
}


void Quad::Render()
{
	_transform->SetWorldBuffer();


		DC->DrawIndexed(_indices.size(), 0, 0);
}

void Quad::CreateVertricesAndIndices()
{
	Vertex_UV v;
	float widthRate = (_size._x) * 0.5f;
}
