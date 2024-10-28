#include "BitcoinExchange.hpp"
#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>

const std::string BitcoinExchange::s_db_name("data.csv");

BitcoinExchange::BitcoinExchange() : m_data(std::map<std::string, double>())  { return; }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bc) : m_data(bc.m_data) { return; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& bc) {
	if (this == &bc)
		return *this;
	m_data = bc.m_data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() { return; }

int BitcoinExchange::print_exchange_rate_from_input(const std::string& file_name) {
	t_error_object status = _read_db();
	switch (status.first) {
		case database_access_error:
			std::cout << "Critical error: could not access database " << status.second << "\n";
			return 1;
		case database_invalid:
			if (status.second == "")
				std::cout << "Critical error: invalid database => {empty}\n";
			else
				std::cout << "Critical error: invalid database => " << status.second << "\n";
			return 1;
		default:
			break;
	}

	status = _read_input(file_name);
	switch (status.first) {
		case input_access_error:
			std::cout << "Critical error: could not access input file " << status.second << "\n";
			return 1;
		default:
			break;
	}
	return 0;
}

bool BitcoinExchange::_has_only_digits(const std::string& str) const {
	return str.find_first_not_of("0123456789") == std::string::npos;
}

bool BitcoinExchange::_is_a_double_str_representation(const std::string& nbr_str) const {
	int number_of_dots = 0;
	for (int i = 0; i < static_cast<int>(nbr_str.length()); i++) {
		if (nbr_str[i] == '.')
			number_of_dots++;
		if (number_of_dots > 1 || (nbr_str[i] != '.' && !isdigit(nbr_str[i])))
			return false;
	}
	return true;
}

bool BitcoinExchange::_is_date_valid(const std::string& str) const {

	size_t year_end_pos = str.find("-");
	size_t month_end_pos = str.find("-", year_end_pos + 1);

	std::string year_str = str.substr(0, year_end_pos);
	std::string month_str = str.substr(year_end_pos + 1, 2);
	std::string day_str = str.substr(month_end_pos + 1, std::string::npos);

	if (year_str.length() != 4 || month_str.length() != 2 || day_str.length() != 2 ||
		!_has_only_digits(year_str) ||!_has_only_digits(month_str) ||!_has_only_digits(day_str))
		return false;

	struct tm date = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	date.tm_year = atoi(year_str.c_str()) - 1900;
	date.tm_mon = atoi(month_str.c_str()) - 1;
	date.tm_mday = atoi(day_str.c_str());
	struct tm normalized_date = date;
	mktime(&normalized_date);
	if (date.tm_year != normalized_date.tm_year || date.tm_mon != normalized_date.tm_mon || date.tm_mday != normalized_date.tm_mday)
		return false;

	return true;
}

void BitcoinExchange::_print_exchange_rate_line(double value, double rate, const std::string& date_str) const {
	std::cout << date_str << " => " << value << " = " << value * rate << "\n";
}

BitcoinExchange::t_error_object BitcoinExchange::_handle_db_line(const std::string& curr_line) {
	std::string delim = ",";
	size_t delim_pos = curr_line.find(delim);
	std::string date_str = curr_line.substr(0, delim_pos);
	std::string rate_str = curr_line.substr(delim_pos + delim.length(), std::string::npos);

	if (delim_pos == std::string::npos || rate_str == "") {
		return std::make_pair(database_invalid, curr_line);
	} else if (!_is_date_valid(date_str)) {
		return std::make_pair(database_invalid, date_str);
	} else if (!_is_a_double_str_representation(rate_str)) {
		return std::make_pair(database_invalid, rate_str);
	}

	double rate = atof(rate_str.c_str());
	if (rate < 0)
		return std::make_pair(database_invalid, rate_str);

	m_data.insert(std::make_pair(date_str, rate));
	return std::make_pair(ok, "All good! :3 👍");
}

void BitcoinExchange::_handle_input_line(const std::string& curr_line) {
	std::string delim = " | ";
	size_t delim_pos = curr_line.find(delim);
	if (delim_pos == std::string::npos) {
		std::cout << "Error: no ' | ' delimeter or value after it => " << curr_line << "\n";
		return;
	}
	std::string date_str = curr_line.substr(0, delim_pos);
	std::string value_str = curr_line.substr(delim_pos + delim.length(), std::string::npos);

	if (delim_pos == std::string::npos || value_str == "") {
		std::cout << "Error: no ' | ' delimeter or value after it => " << curr_line << "\n";
		return;
	}
	else if (!_is_date_valid(date_str)) {
		std::cout << "Error: bad input => " << date_str << "\n";
		return;
	}

	double value = atof(value_str.c_str());
	if (value > 1000) {
		std::cout << "Error: the number is too large => " << value << "\n" ;
		return;
	} else if (value < 0 || !_is_a_double_str_representation(value_str)) {
		std::cout << "Error: not a positive number => " << value_str << "\n" ;
		return;
	}

	t_iterator res = m_data.find(date_str);
	if (res != m_data.end()) {
		_print_exchange_rate_line(value, res->second, date_str);
		return;
	}
	if ((--m_data.end())->first < date_str) {
		_print_exchange_rate_line(value, (--m_data.end())->second, date_str);
		return;
	}

	t_iterator curr = m_data.begin();
	for (t_iterator it = m_data.begin(); it != m_data.end(); it++) {
		if (it->first > date_str) {
			_print_exchange_rate_line(value, curr->second, date_str);
			return;
		}
		curr = it;
	}
}

BitcoinExchange::t_error_object BitcoinExchange::_read_db() {
	std::ifstream file(s_db_name.c_str());
	if (!file)
		return std::make_pair(database_access_error, s_db_name);

	std::string curr_line("");
	std::getline(file, curr_line);
	t_error_object status(ok, "All good! :3 👍");
	if (curr_line != "date,exchange_rate") {
		status = _handle_db_line(curr_line);
		if (status.first != ok) {
			file.close();
			return status;
		}
	}
	while (std::getline(file, curr_line)) {
		status = _handle_db_line(curr_line);
		if (status.first != ok) {
			break;
		}
	}
	file.close();
	return status;
}

BitcoinExchange::t_error_object BitcoinExchange::_read_input(const std::string& file_name) {
	std::ifstream file(file_name.c_str());
	if (!file) {
		return std::make_pair(input_access_error, file_name);
	}

	std::string curr_line("");
	std::getline(file, curr_line);
	if (curr_line != "date | value") {
		_handle_input_line(curr_line);
	}
	while (std::getline(file, curr_line)) {
		_handle_input_line(curr_line);
	}

	file.close();
	return std::make_pair(ok, "All good! :3 👍");
}
