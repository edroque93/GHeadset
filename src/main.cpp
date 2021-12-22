#include <iostream>
#include <hidapi/hidapi.h>

int main(const int argc, const char **argv)
{
	std::cout << "Hello world" << std::endl;
	int resinit = hid_init();
	int resexit = hid_exit();

	return 0;
}