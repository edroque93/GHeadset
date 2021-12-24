#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unistd.h>
#include <hidapi/hidapi.h>

#define HIDPP_LONG_MESSAGE_LENGTH  20

void calcGammaCorrection()
{
	std::cout << "std::vector<uint8_t> gammaCorrection = {";
	for (int i = 0; i < 0x100; i++)
	{
		if (!(i%16)) std::cout << "\n\t";
		int value = std::pow(i/255.0, 2.5) * 255;
		std::cout << std::setw(3) << value << ", ";
	}
	std::cout << "\n};" << std::endl;
}

std::vector<uint8_t> gammaCorrection = {
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1, 
	1,   1,   1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3, 
	3,   4,   4,   4,   4,   5,   5,   5,   5,   6,   6,   6,   6,   7,   7,   7, 
	8,   8,   8,   9,   9,   9,  10,  10,  10,  11,  11,  11,  12,  12,  13,  13, 
	14,  14,  14,  15,  15,  16,  16,  17,  17,  18,  18,  19,  19,  20,  21,  21, 
	22,  22,  23,  23,  24,  25,  25,  26,  27,  27,  28,  29,  29,  30,  31,  31, 
	32,  33,  34,  34,  35,  36,  37,  37,  38,  39,  40,  41,  42,  42,  43,  44, 
	45,  46,  47,  48,  49,  50,  51,  52,  52,  53,  54,  55,  56,  57,  59,  60, 
	61,  62,  63,  64,  65,  66,  67,  68,  69,  71,  72,  73,  74,  75,  77,  78, 
	79,  80,  82,  83,  84,  85,  87,  88,  89,  91,  92,  93,  95,  96,  98,  99, 
	100, 102, 103, 105, 106, 108, 109, 111, 112, 114, 115, 117, 119, 120, 122, 123, 
	125, 127, 128, 130, 132, 133, 135, 137, 138, 140, 142, 144, 145, 147, 149, 151, 
	153, 155, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 
	184, 186, 188, 190, 192, 194, 197, 199, 201, 203, 205, 207, 210, 212, 214, 216, 
	219, 221, 223, 226, 228, 230, 233, 235, 237, 240, 242, 245, 247, 250, 252, 255, 
};

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
	data[6] = gammaCorrection[r]; // R
	data[7] = gammaCorrection[g]; // G
	data[8] = gammaCorrection[b]; // B
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
	hid_exit();

	return 0;
}