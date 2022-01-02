// Logictech headset, product 0x0ab5

#pragma once

#include <array>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cmath>
#include <hidapi/hidapi.h>
#include <thread>

#include "color.hpp"
#include "device.hpp"
#include "hid.hpp"

namespace GHeadset::dev
{
    class Dev_0ab5: public Device
    {
        public:
            enum class LEDStrip { Top, Bottom, Both };

            Dev_0ab5();

            inline uint16_t getProduct() override { return 0x0ab5; };

            void setLightOff(LEDStrip led = LEDStrip::Both);
            void setLightFixed(Color::RGB color, LEDStrip led = LEDStrip::Both);
        private:
            static const std::chrono::milliseconds delayMs;
        	static std::array<uint8_t, GHeadset::hid::longMessageLength> offStripTemplate;
        	static std::array<uint8_t, GHeadset::hid::longMessageLength> colorStripTemplate;

            std::unique_ptr<hid_device, decltype(&hid_close)> device;
            std::chrono::time_point<std::chrono::system_clock> lastCmd;

            double estimateBatteryPercentage(uint16_t voltage);
    };
}