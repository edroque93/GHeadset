#pragma once

#include <stdint.h>

namespace GHeadset::hid
{
    static const uint16_t logitechVendor = 0x046d;
    
    static const uint8_t longMessageOp = 0x11;
    static const uint8_t longMessageLength = 0x14;
}
