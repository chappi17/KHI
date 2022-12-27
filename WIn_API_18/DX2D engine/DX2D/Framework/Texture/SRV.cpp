#include "framework.h"
#include "SRV.h"

SRV::SRV(wstring file)
{
    ScratchImage image;
    LoadFromWICFile(file.data(), WIC_FLAGS_NONE, nullptr, image);

    CreateShaderResourceView(DEVICE.Get(), image.GetImages(), image.GetImageCount(), image.GetMetadata(),
        _shaderResourceView.GetAddressOf());

    _size.x = image.GetMetadata().width;
    _size.y = image.GetMetadata().height;
}

SRV::~SRV()
{
}

void SRV::Set(int slot)
{
    DC->PSSetShaderResources(slot, 1, _shaderResourceView.GetAddressOf());
}
