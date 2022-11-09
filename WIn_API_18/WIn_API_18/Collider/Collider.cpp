#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
    _pens[0] = CreatePen(0, 3, RED);
    _pens[1] = CreatePen(0, 3, GREEN);
    _curPen = _pens[1];
}

Collider::~Collider()
{
}

void Collider::SetRED()
{
  //  _curPen = _pens[0];
}

void Collider::SetGREEN()
{
//    _curPen = _pens[1];
}

bool Collider::IsCollision(Vector2 pos)
{
    return false;
}

bool Collider::IsCollision(shared_ptr<Collider> col)
{
    switch (col->GetType())
    {
    case ColliderType :: NONE:
    {
        break;
    }

    case ColliderType::CIRCLE:
    {
        return IsCollision(dynamic_pointer_cast<CircleCollider>(col));
        break;
    }


    case ColliderType::RECT:
    {
       return IsCollision(dynamic_pointer_cast<RectCollider>(col));
        break;
    }
    default:
        break;
    }

    return false;
}

