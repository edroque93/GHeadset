#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unistd.h>
#include <hidapi/hidapi.h>

#include "color.hpp"
#include "dev_0ab5.hpp"

#define HIDPP_LONG_MESSAGE_LENGTH  20

enum class LedStrip
{
	Up,
	Bottom,
	Both
};

void set_fixed(hid_device* dev, uint8_t r, uint8_t g, uint8_t b, LedStrip ledStrip)
{
	std::vector<uint8_t> data(HIDPP_LONG_MESSAGE_LENGTH, 0);
	data[0] = 0x11; // Long message
	data[1] = 0xff; // Device
	data[2] = 0x04;
	data[3] = 0x3f;
	data[4] = 0x00; // 0 bottom led strip, 1 upper led strip
	data[5] = 0x01;
	data[6] = GHeadset::Color::gammaCorrection[r]; // R
	data[7] = GHeadset::Color::gammaCorrection[g]; // G
	data[8] = GHeadset::Color::gammaCorrection[b]; // B
	data[9] = 0x02;

	// TODO: gamma correction on RGB values

	if (ledStrip == LedStrip::Bottom || ledStrip == LedStrip::Both)
	{
		hid_write(dev, data.data(), HIDPP_LONG_MESSAGE_LENGTH);
	}
	if (ledStrip == LedStrip::Both) usleep(10*1000); // It seems it requires a longer sleep
	if (ledStrip == LedStrip::Up || ledStrip == LedStrip::Both)
	{
		data[4] = 0x01;
		hid_write(dev, data.data(), HIDPP_LONG_MESSAGE_LENGTH);
	}
}

void turnOff(hid_device* dev)
{
	std::vector<uint8_t> data(HIDPP_LONG_MESSAGE_LENGTH, 0);
	data[0] = 0x11; // Long message
	data[1] = 0xff; // Device
	data[2] = 0x04;
	data[3] = 0x3e;
	data[4] = 0x00; // Led strip

    hid_write(dev, data.data(), HIDPP_LONG_MESSAGE_LENGTH);
    usleep(1000);
	data[4] = 0x01;
    hid_write(dev, data.data(), HIDPP_LONG_MESSAGE_LENGTH);
}

int main(const int argc, const char **argv)
{
	(void)argc;
	(void)argv;
	std::cout << "Hello world" << std::endl;
	hid_init();
/*
	// 0x046d == Logitech; 0x0ab5 == G733
	hid_device_info* devs = hid_enumerate(0x046d, 0x0ab5); // vendor, product (ushort)
	
	if (devs != nullptr)
	{
		hid_device* dev = hid_open_path(devs->path);
		std::cout << std::to_string((uint64_t)dev) << std::endl;
		if (dev != nullptr)
		{
			turnOff(dev);
			// set_fixed(dev, 0xff, 0, 0, LedStrip::Up);
			// usleep(100*1000);
			// set_fixed(dev, 0, 0xff, 0, LedStrip::Bottom);
			// usleep(100*1000);
			// set_fixed(dev, 0x52, 0x80, 0x71, LedStrip::Both); // #528071
		}
	}

	hid_free_enumeration(devs);
// */
	GHeadset::dev::Dev_0ab5 assd;
	auto dev = assd.getDevice();
	turnOff(dev.get());

	hid_exit();

	return 0;
}