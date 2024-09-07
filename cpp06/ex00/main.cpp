#include "ScalarConverter.hpp"
#include <iostream>

void test_converter(std::string str) {
	std::cout << "Tested literal: " << str << "\n";
	ScalarConverter::convert(str);
	std::cout << "===\n";
}

int main (void) {
	test_converter("42");
	test_converter("0");
	test_converter("2147483647");
	test_converter("2147483648");
	test_converter("-2147483648");
	test_converter("-2147483649");
	test_converter("a");
	test_converter("ab");
	test_converter("5.24f");
	test_converter("42.84f");
	test_converter("42.84");
	test_converter("nan");
	test_converter("nanf");
	test_converter("inf");
	test_converter("inff");
	test_converter("-inf");
	test_converter("-inff");
	return 0;
}
