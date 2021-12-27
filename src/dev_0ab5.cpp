#include "dev_0ab5.hpp"

using namespace GHeadset::dev;

const std::vector<uint8_t> Dev_0ab5::offBottomStrip {
	GHeadset::hid::longMessageOp,
	0xff, // Device
	0x04,
	0x3e,
	0x00, // Bottom LED strip
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 // Fill to GHeadset::hid::longMessageLength
};

const std::vector<uint8_t> Dev_0ab5::offTopStrip {
	GHeadset::hid::longMessageOp,
	0xff, // Device
	0x04,
	0x3e,
	0x01, // Top LED strip
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 // Fill to GHeadset::hid::longMessageLength
};

// TODO: fixed RGB has variable bytes (RGB, duh), this ^^^ scheme is ugly

void Dev_0ab5::turnOff(hid_device* dev)
{
    GHeadset::hid::write(dev, offTopStrip);
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    GHeadset::hid::write(dev, offBottomStrip);
}