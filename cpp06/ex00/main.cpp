#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Correct usage: ./convert [scalar literal]";
		return 1;
	}
	const std::string arg = argv[1];
	ScalarConverter::convert(arg);
	return 0;
}
