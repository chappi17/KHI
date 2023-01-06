#include "framework.h"
#include "Collider.h"

bool Collider::_isDebug = true;
Collider::Collider()
{
}

Collider::~Collider()
{
}

void Collider::Update()
{
    if (isActive == false)
        return;
    _transform->Update();
    _colorBuffer->Update();
}

void Collider::Render()
{
    if (isActive == false || _isDebug == false)
        return;
    _transform->SetWorldBuffer();
    _colorBuffer->SetPSBuffer(0);

    _vertexBuffer->IASet(0);

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs->Set();
    _ps->Set();

    DC->Draw(_vertices.size(), 0);
}

void Collider::SetRED()
{
    _colorBuffer->_data.color = { 255,0,0,1.0f };
}

void Collider::SetGREEN()
{
    _colorBuffer->_data.color = { 0,255,0,1.0f };
}

bool Collider::IsCollision(shared_ptr<Collider> col, bool isObb)
{
    if (isActive == false)
        return false;

    switch (col->GetType())
    {
    case ColliderType::NONE:
    {
        break;
    }

    case ColliderType::CIRCLE:
    {
        if (isObb)
            return OBB(dynamic_pointer_cast<CircleCollider>(col));
        return IsCollision(dynamic_pointer_cast<CircleCollider>(col));
        break;
    }

    case ColliderType::RECT:
    {
        if (isObb)
            return OBB(dynamic_pointer_cast<RectCollider>(col));
        return IsCollision(dynamic_pointer_cast<RectCollider>(col));
        break;
    }

    default:
        break;
    }

    return false;
}

void Collider::CreateData()
{
    _vs = make_shared<VertexShader>(L"Collider/ColliderVertexShader");
    _ps = make_shared<PixelShader>(L"Collider/ColliderPixelShader");

    UINT stride = static_cast<UINT>(sizeof(Vertex_Bagic));
    _vertexBuffer = make_shared<VertexBuffer>(&_vertices[0], stride, _vertices.size());
    _colorBuffer = make_shared<ColorBuffer>();

    _transform = make_shared<Transform>();
}
