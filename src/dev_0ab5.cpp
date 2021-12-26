#include "dev_0ab5.hpp"

#include <iostream>

using namespace GHeadset::dev;

void Dev_0ab5::turnOff(hid_device* dev)
{
	std::vector<uint8_t> data(GHeadset::hid::longMessageLength, 0);
	data[0] = 0x11; // Long message
	data[1] = 0xff; // Device
	data[2] = 0x04;
	data[3] = 0x3e;
	data[4] = 0x00; // Led strip

    GHeadset::hid::write(dev, data);
    //usleep(1000);
	data[4] = 0x01;
    GHeadset::hid::write(dev, data);
}