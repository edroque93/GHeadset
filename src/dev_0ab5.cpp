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

std::array<uint8_t, GHeadset::hid::longMessageLength> Dev_0ab5::batteryRequest {
	GHeadset::hid::longMessageOp,
	0xff, // Device
	0x08,
	0x0a,
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
	// TODO: fitness for device 0x0ab5 is bad, discharge curve must be adjusted

	if (voltage < 3350) return 0.0;
    if (voltage > 4050) return 100.0;

	// Don't mind me if tryhard
	std::array<double, 6> coefficients = { 
		+ 3335.7537253883 - voltage,
		+ 29.4585516521,
		- 1.2640874846,
		+ 0.0257550053,
		- 0.0002345719,
		+ 8.11262335099624E-07
	};
	std::array<double, 10> roots;
	std::unique_ptr<gsl_poly_complex_workspace, decltype(&gsl_poly_complex_workspace_free)> workspace(gsl_poly_complex_workspace_alloc(6), gsl_poly_complex_workspace_free);
	gsl_poly_complex_solve (coefficients.data(), coefficients.size(), workspace.get(), roots.data());

	size_t realSolutionIndex = 0;
	size_t rootCount = roots.size() >> 1;
	for (size_t i = 0; i < rootCount; i++)
	{
		if (std::abs(roots[2*i+1]) == std::min(std::abs(roots[2*i+1]), std::abs(roots[2*realSolutionIndex+1])))
		{
			realSolutionIndex = i;
		}
	}
	return roots[realSolutionIndex*2];
}

double Dev_0ab5::getBatteryPercentage()
{
	GHeadset::hid::write(device.get(), batteryRequest);
    std::array<uint8_t, 7> data;
    int readResult = hid_read_timeout(device.get(), data.data(), data.size(), 5000);
	if (readResult <= 0) throw std::runtime_error("Battery request error or timed out");
	uint16_t voltage = (data[4] << 8) | data[5];
	return estimateBatteryPercentage(voltage);
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
