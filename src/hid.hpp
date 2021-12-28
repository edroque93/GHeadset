#pragma once

#include <array>
#include <cstdint>
#include <vector>
#include <hidapi/hidapi.h>

namespace GHeadset::hid
{
    const uint16_t logitechVendor = 0x046d;

    const uint8_t longMessageOp = 0x11;
    const uint8_t longMessageLength = 0x14;

    template<std::size_t S>
    inline int write(hid_device* dev, std::array<uint8_t, S> data)
    {
        return hid_write(dev, data.data(), S);
    }
}
