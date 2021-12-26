// Logictech headset, product 0x0ab5

#pragma once

#include <vector>
#include <cstdint>
#include <hidapi/hidapi.h>

#include "device.hpp"
#include "hid.hpp"

namespace GHeadset::dev
{
    class Dev_0ab5: public Device
    {
        public:
            enum class LEDStrip { Top, Bottom, Both };

            // This should be static info
            uint16_t getProduct() override { return 0x0ab5; };

            void turnOff(hid_device* dev);
    };
}