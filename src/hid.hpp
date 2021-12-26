#pragma once

#include <cstdint>
#include <vector>
#include <hidapi/hidapi.h>


namespace GHeadset::hid
{
    static const uint16_t logitechVendor = 0x046d;
    
    static const uint8_t longMessageOp = 0x11;
    static const uint8_t longMessageLength = 0x14;

    static inline int write(hid_device* dev, std::vector<uint8_t> data)
    {
        return hid_write(dev, data.data(), data.size());
    }
}
