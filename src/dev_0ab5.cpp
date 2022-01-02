#include "dev_0ab5.hpp"

using namespace std::literals;
using namespace GHeadset::dev;

// Static initialization

const std::chrono::milliseconds Dev_0ab5::delayMs = 10ms;

std::array<uint8_t, GHeadset::hid::longMessageLength> Dev_0ab5::offStripTemplate {
	GHeadset::hid::longMessageOp,
	0xff, // Device
	0x04,
	0x3e,
	0x00, // LED strip
};

std::array<uint8_t, GHeadset::hid::longMessageLength> Dev_0ab5::colorStripTemplate {
	GHeadset::hid::longMessageOp,
	0xff, // Device
	0x04,
	0x3f,
	0x00, // LED strip
	0x01,
	0x00, // R
	0x00, // G
	0x00, // B
	0x02,
};

Dev_0ab5::Dev_0ab5() : device(getDevice())
{
	if (device == nullptr)
		throw std::runtime_error("Cannot open device 0x0ab5");
}

double Dev_0ab5::estimateBatteryPercentage(uint16_t voltage)
{
	// Based on empirical data from github:
	// https://github.com/ashkitten/g933-utils/blob/master/libg933/src/maps/0A5B/discharging.csv
	// TODO: check fitness for device 0x0ab5

	if (voltage < 3350) return 0.0;
    if (voltage > 4050) return 100.0;
	return 
		+ 9.13360662041828E-07 * std::pow(voltage, 5) 
		- 0.000256641 * std::pow(voltage, 4) 
		+ 0.0270439922 * std::pow(voltage, 3) 
		- 1.2500185151 * std::pow(voltage, 2) 
		+ 26.4924075939 * voltage
		+ 3392.3839476991;
}

void Dev_0ab5::setLightOff(LEDStrip led)
{
	if (led == LEDStrip::Top || led == LEDStrip::Both) 
	{
		colorStripTemplate[4] = 1;
		GHeadset::hid::write(device.get(), offStripTemplate);
	}
	if (led == LEDStrip::Both) std::this_thread::sleep_for(Dev_0ab5::delayMs);
	if (led == LEDStrip::Bottom || led == LEDStrip::Both)
	{
		colorStripTemplate[4] = 0;
		GHeadset::hid::write(device.get(), offStripTemplate);
	}
	lastCmd = std::chrono::system_clock::now();
}

void Dev_0ab5::setLightFixed(Color::RGB color, LEDStrip led)
{
	auto diff = Dev_0ab5::delayMs - std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - lastCmd);
	std::this_thread::sleep_for(diff);
	colorStripTemplate[6] = GHeadset::Color::gammaCorrection[color.red];
	colorStripTemplate[7] = GHeadset::Color::gammaCorrection[color.green];
	colorStripTemplate[8] = GHeadset::Color::gammaCorrection[color.blue];
	if (led == LEDStrip::Top || led == LEDStrip::Both) 
	{
		colorStripTemplate[4] = 1;
		GHeadset::hid::write(device.get(), colorStripTemplate);
	}
	if (led == LEDStrip::Both) std::this_thread::sleep_for(Dev_0ab5::delayMs);
	if (led == LEDStrip::Bottom || led == LEDStrip::Both)
	{
		colorStripTemplate[4] = 0;
		GHeadset::hid::write(device.get(), colorStripTemplate);
	}
	lastCmd = std::chrono::system_clock::now();
}
