#pragma once

#include <cstdint>
#include <memory>
#include <hidapi/hidapi.h>

#include "hid.hpp"

namespace GHeadset::dev
{
    class Device
    {
        public:
            virtual ~Device() { }

            virtual uint16_t getProduct() = 0;
            virtual const wchar_t* getSerialNumber() { return nullptr; };

            std::unique_ptr<hid_device, decltype(&hid_close)> getDevice()
            {
                return std::unique_ptr<hid_device, decltype(&hid_close)> (hid_open(GHeadset::hid::logitechVendor, getProduct(), nullptr), hid_close);
                //return devs; 
            }
    };
}