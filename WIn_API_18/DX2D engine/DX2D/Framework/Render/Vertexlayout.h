#pragma once

struct Vertex_Bagic
{
    Vertex_Bagic()
    {
    }

    Vertex_Bagic(float x, float y)
    {
        this->pos.x = x;
        this->pos.y = y;
    }

    XMFLOAT3 pos = { 0.0f,0.0f,0.0f };
};

struct Vertex_Color
{
    XMFLOAT3 pos;
    XMFLOAT4 color;
};

struct Vertex_UV
{
    XMFLOAT3 pos;
    XMFLOAT2 uv; // 텍스쳐 좌표
};
