#pragma once

#include <cstdint>
#include <hidapi/hidapi.h>
#include <memory>

#include "hid.hpp"

namespace GHeadset::dev
{
    class Device
    {
        public:
            virtual ~Device() { }

            virtual inline uint16_t getProduct() = 0;
            virtual inline const wchar_t* getSerialNumber() { return nullptr; };
        protected:
            virtual inline std::unique_ptr<hid_device, decltype(&hid_close)> getDevice()
            {
                return std::unique_ptr<hid_device, decltype(&hid_close)> (hid_open(GHeadset::hid::logitechVendor, getProduct(), nullptr), hid_close);
            }
    };
}