#include "convert.hpp"
#include <cmath>
#include <limits>
#include <iostream>
#include <cerrno>

static bool is_printable_non_numeric(char c) {
	return ((c > 31 && c < '0') || (c > '9' && c < 127));
}


static void print_error(const std::string& type, enum e_error err) {
	switch (err) {
		case bad_literal:
			std::cerr << "\033[0;31m""Error\nBad literal\n""\033[0m";
			return;
		case too_big_literal:
			std::cerr << "\033[0;31m""Error\nLiteral is too large for " << type
				<< " type\n""\033[0m";
			return;
	}
}

static bool is_char_overflows(int c) {
	return c > std::numeric_limits<char>::max() ||
		 c < std::numeric_limits<char>::min();
}

static bool is_int_overflows(const std::string& str) {
	long num = strtol(str.c_str(), 0, 10);
	return (num == std::numeric_limits<long>::max() && errno == ERANGE) ||
		(num == std::numeric_limits<long>::min() && errno == ERANGE) ||
		(num > std::numeric_limits<int>::max() ||
		 num < std::numeric_limits<int>::min());
}

static bool is_float_overflows(const std::string& str, float num) {
	return str != "inff" && str != "-inff" && std::isinf(num);
}

static bool is_double_overflows(const std::string& str, double num) {
	return str != "inf" && str != "-inf" && std::isinf(num);
}

void convert_from_char(const std::string& str) {
	char char_num = str[0];

	if (!is_printable_non_numeric(char_num))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << char_num << "\n";
	std::cout << "int: " << static_cast<int>(char_num) << "\n";
	std::cout << "float: " << static_cast<float>(char_num) << "f" << "\n";
	std::cout << "double: " << static_cast<double>(char_num) << "\n";
}

void convert_from_int(const std::string& str) {
	int int_num = atoi(str.c_str());
	bool overflows = is_int_overflows(str.c_str());

	if (overflows)
		return print_error("int", too_big_literal);
	if ((int_num == 0 && str != "0"))
		return print_error("int", bad_literal);

	if (is_char_overflows(int_num))
		std::cout << "char: impossible\n";
	else if (!is_printable_non_numeric(static_cast<char>(int_num)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(int_num) << "\n";
	std::cout << "int: " << int_num << "\n";
	std::cout << "float: " << static_cast<float>(int_num) << "f" << "\n";
	std::cout << "double: " << static_cast<double>(int_num) << "\n";
}

void convert_from_float(const std::string& str) {
	float float_num = static_cast<float>(atof(str.c_str()));
	bool overflows = is_float_overflows(str, float_num);

	if (overflows)
		return print_error("float", too_big_literal);
	if ((float_num == 0 && str != "0.0f"))
		return print_error("float", bad_literal);

	if (is_char_overflows(static_cast<int>(float_num)))
		std::cout << "char: impossible\n";
	else if (!is_printable_non_numeric(static_cast<char>(float_num)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(float_num) << "\n";

	if (static_cast<long>(float_num) > std::numeric_limits<int>::max() ||
		static_cast<long>(float_num) < std::numeric_limits<int>::min() ||
		std::isnan(float_num) || std::isinf(float_num))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(float_num) << "\n";

	std::cout << "float: " << float_num << "f" << "\n";
	std::cout << "double: " << static_cast<double>(float_num) << "\n";
}

void convert_from_double(const std::string& str) {
	double double_num = atof(str.c_str());
	bool overflows = is_double_overflows(str, double_num);

	if (overflows)
		return print_error("double", too_big_literal);
	if ((double_num == 0 && str != "0.0"))
		return print_error("double", bad_literal);

	if (is_char_overflows(static_cast<int>(double_num)))
		std::cout << "char: impossible\n";
	else if (!is_printable_non_numeric(static_cast<char>(double_num)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(double_num) << "\n";

	if (static_cast<long>(double_num) > std::numeric_limits<int>::max() ||
		static_cast<long>(double_num) < std::numeric_limits<int>::min() ||
		std::isnan(double_num) || std::isinf(double_num))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(double_num) << "\n";

	std::cout << "float: " << static_cast<float>(double_num) << "f" << "\n";
	std::cout << "double: " << double_num << "\n";
}

enum e_type infer_type(const std::string& scalar_str) {
	if (scalar_str == "nan" || scalar_str == "-inf" || scalar_str == "inf")
		return double_type;
	else if (scalar_str == "nanf" || scalar_str == "-inff" || scalar_str == "inff")
		return float_type;
	else if (*scalar_str.rbegin() != '.' && scalar_str.find(".") != std::string::npos) {
		if (*scalar_str.rbegin() == 'f')
			return float_type;
		else
			return double_type;
	}
	else if (scalar_str.size() == 1 && is_printable_non_numeric(scalar_str[0]))
		return char_type;
	return int_type;
}
