#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <string>
enum e_error
{
    bad_literal,
    too_big_literal,
};

enum e_type
{
    char_type,
    int_type,
    float_type,
    double_type,
};

enum e_type infer_type(const std::string& scalar_str);
void convert_from_double(const std::string& str);
void convert_from_float(const std::string& str);
void convert_from_int(const std::string& str);
void convert_from_char(const std::string& str);
#endif
