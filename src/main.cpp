#include <iostream>

#include "color.hpp"
#include "dev_0ab5.hpp"

int main(const int argc, const char **argv)
{
	(void)argc;
	(void)argv;
	std::cout << "Hello world" << std::endl;

	GHeadset::dev::Dev_0ab5 headset;
	headset.setLightOff();

	for (int i = 0; i < 10; i++)
	{
		headset.setLightFixed(GHeadset::Color::Palette::Red);
		headset.setLightFixed(GHeadset::Color::Palette::Green);
		headset.setLightFixed(GHeadset::Color::Palette::Blue);
	}

	return 0;
}