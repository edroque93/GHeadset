#include <iostream>
#include <string>
#include <vector>

#include "dev_0ab5.hpp"
#include "parameterparser.hpp"

enum class Command
{
	None,
	LightsOff,
	FixedLight,
	BatteryCheck,
};

GHeadset::Color::RGB parseColor(std::string rgb)
{
	size_t size = rgb.length();
	if ((size == 7 && rgb[0] != '#') || size < 6 || size > 7) throw std::runtime_error("Cannot parse color");
	return GHeadset::Color::RGB(
		std::strtol(rgb.substr(1, 2).data(), nullptr, 16),
		std::strtol(rgb.substr(3, 2).data(), nullptr, 16),
		std::strtol(rgb.substr(5, 2).data(), nullptr, 16));
}

int main(const int argc, const char **argv)
{
	try
	{
		Command cmd = Command::None;
		GHeadset::Color::RGB rgbColor = GHeadset::Color::Palette::AliceBlue;

		GHeadset::utils::ParameterParser parser("GHeadset", [](auto){});
		parser.registerSwitch("lightsoff", "Set headset lights off", "Commands", [&cmd]() { cmd = Command::LightsOff; });
		parser.registerSwitch("battery", "Get battery level", "Commands", [&cmd]() { cmd = Command::BatteryCheck; });
		parser.registerParameter("fixedlight", "Set headset light to fixed value in the format RRGGBB", "Commands", [&cmd, &rgbColor](std::string rgb) { rgbColor = parseColor(rgb); cmd = Command::FixedLight; });
		parser.parse(std::vector<std::string>(argv + 1, argv + argc));

		switch (cmd)
		{
			case Command::None:
				std::cout << "Command not provided" << std::endl;
				break;
			case Command::LightsOff:
			{
				GHeadset::dev::Dev_0ab5 headset;
				headset.setLightOff();
				break;
			}
			case Command::FixedLight:
			{
				GHeadset::dev::Dev_0ab5 headset;
				headset.setLightFixed(rgbColor);
				break;
			}
			case Command::BatteryCheck:
			{
				GHeadset::dev::Dev_0ab5 headset;
				std::cout << "Battery: " << headset.getBatteryPercentage() << "%" << std::endl;
				break;
			}
			default:
				std::cout << "Command not supported (yet)" << std::endl;
				break;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "There was a problem: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}