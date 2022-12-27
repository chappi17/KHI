#include "framework.h"
#include "Quad.h"

Quad::Quad(wstring file)
{
	wstring path = L"Resource/Texture/" + file;
	_srv = SRVManager::GetInstance()->AddSRV(path);
	_size = _srv->GetSize();

	_transform = make_shared<Transform>();

	CreateVertricesAndIndices();
	_vBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_UV), _vertices.size());
	_indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());

	_vs = ADD_VS(L"TextureVertexShader");
	_ps = ADD_PS(L"TexturePixelShader");
}

Quad::Quad(wstring file, Vector2 size)
	: _size(size)
{
	wstring path = L"Resource/Texture/" + file;
	_srv = SRVManager::GetInstance()->AddSRV(path);
	_transform = make_shared<Transform>();

	CreateVertricesAndIndices();
	_vBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_UV), _vertices.size());
	_indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());

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

	_vBuffer->IASet(0);
	_indexBuffer->IASet();

	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_srv->Set(0);
	SAMPLER->Set(0);

	_vs->Set();
	_ps->Set();

	DC->DrawIndexed(_indices.size(), 0, 0);
}

void Quad::CreateVertricesAndIndices()
{
	Vertex_UV v;
	float widthRate = (_size.x) * 0.5f;
	float heightRate = (_size.y) * 0.5f;
	v.pos = { -widthRate, heightRate, 0.0f }; // 왼쪽 위
	v.uv = { 0.0f, 0.0f };
	_vertices.push_back(v);

	v.pos = { widthRate, -heightRate, 0.0f }; // 오른쪽 아래
	v.uv = { 1.0f,1.0f };
	_vertices.push_back(v);

	v.pos = { -widthRate, -heightRate, 0.0f }; // 왼쪽 아래
	v.uv = { 0.0f, 1.0f };
	_vertices.push_back(v);

	v.pos = { widthRate, heightRate, 0.0f }; // 오른쪽 위
	v.uv = { 1.0f, 0.0f };
	_vertices.push_back(v);


	_indices.push_back(0);
	_indices.push_back(1);
	_indices.push_back(2);

	_indices.push_back(0);
	_indices.push_back(3);
	_indices.push_back(1);
}
