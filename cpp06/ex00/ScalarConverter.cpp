#include "ScalarConverter.hpp"
#include "convert.hpp"

void ScalarConverter::convert(const std::string& str) {
	enum e_type type = infer_type(str);
	switch (type) {
		case char_type:
			convert_from_char(str); break;
		case int_type:
			convert_from_int(str); break;
		case float_type:
			convert_from_float(str); break;
		case double_type:
			convert_from_double(str); break;
	}
}
