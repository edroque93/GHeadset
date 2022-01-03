#include <iostream>
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

int main(const int argc, const char **argv)
{
	try
	{
		Command Cmd = Command::None;
		GHeadset::utils::ParameterParser parser("GHeadset", [](auto){});
		parser.registerSwitch("lightsoff", "Set headset lights off", "Commands", [&Cmd]() { Cmd = Command::LightsOff; });
		parser.registerSwitch("battery", "Get battery level", "Commands", [&Cmd]() { Cmd = Command::BatteryCheck; });
		parser.registerParameter("fixedlight", "Set headset light to fixed value in the format #RRGGBB", "Commands", [&Cmd](std::string rgb) { (void) rgb; Cmd = Command::FixedLight; });
		parser.parse(std::vector<std::string>(argv + 1, argv + argc));

		switch (Cmd)
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
				headset.setLightFixed(GHeadset::Color::Palette::DarkOrange);
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