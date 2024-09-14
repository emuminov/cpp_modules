#include "BitcoinExchange.hpp"
#include <iostream>
#include <limits>
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

void BitcoinExchange::print_exchange_rate_from_input(const std::string& file_name) {
	_read_db();
	_read_input(file_name);
}

// TODO: turn this function to date validation function that uses mktime()
// https://stackoverflow.com/questions/9436697/c-check-if-a-date-is-valid
BitcoinExchange::t_date BitcoinExchange::_str_to_date(const std::string& str) {
	BitcoinExchange::t_date date;

	size_t year_end_pos = str.find("-");
	size_t month_end_pos = str.find("-", year_end_pos + 1);

	std::string year_str = str.substr(0, year_end_pos);
	std::string month_str = str.substr(year_end_pos + 1, 2);
	std::string day_str = str.substr(month_end_pos + 1, std::string::npos);

	return date;
}

enum BitcoinExchange::e_error BitcoinExchange::_read_db() {
	std::ifstream file(s_db_name.c_str());
	if (!file)
		return database_access_error;

	std::string curr_line("");
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // TODO: validate the header
	while (std::getline(file, curr_line)) {
		size_t delim_pos = curr_line.find(",");
		std::string date_str = curr_line.substr(0, delim_pos);
		std::string rate_str = curr_line.substr(delim_pos + 1, std::string::npos); // TODO: check if the comma is the last char

		// validate(date_str) TODO: do input validation
		// validate(rate_str) TODO: do input validation
		double rate = atof(rate_str.c_str());
		
		m_data.insert(std::make_pair(date_str, rate));
	}

	file.close();
	if (m_data.size() == 0) {
		return empty_database;
	}
	return ok;
}

enum BitcoinExchange::e_error BitcoinExchange::_read_input(const std::string& file_name) {
	std::ifstream file(file_name.c_str());
	if (!file)
		return input_access_error;

	std::string curr_line("");
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // TODO: validate the header

	while (std::getline(file, curr_line)) {
		std::string delim = " | ";
		size_t delim_pos = curr_line.find(delim);
		std::string date_str = curr_line.substr(0, delim_pos);
		std::string value_str = curr_line.substr(delim_pos + delim.length(), std::string::npos); // TODO: check if the comma is the last char

		// validate(date_str) TODO: do input validation
		// TODO: do a date validation
		double value = atof(value_str.c_str()); // TODO: maybe convert either to an int or to a float
		// TODO: do value validation
		// should be from 0 to 1000
		if (value > 1000) {
			std::cout << "Error: too large a number.\n" ;
			continue;
		} else if (value < 0) {
			std::cout << "Error: not a positive number.\n" ;
			continue;
		}
		
		iterator res = m_data.find(date_str);
		if (res != m_data.end())
			std::cout << date_str << " => " << value << " = " << value * res->second << "\n";
		else {
			// TODO: what if it's empty?
			if (m_data.begin()->first > date_str) {
				std::cout << date_str << " => " << value << " = " << value * m_data.begin()->second << "\n";
				continue;
			} else if ((--m_data.end())->first < date_str) {
				std::cout << date_str << " => " << value << " = " << value * (--m_data.end())->second << "\n";
				continue;
			}
			iterator curr = m_data.begin();
			for (iterator it = m_data.begin(); it != m_data.end(); it++) {
				if (it->first > date_str) {
					std::cout << date_str << " => " << value << " = " << value * curr->second << "\n";
					break;
				}
				curr = it;
			}
		}
	}

	file.close();
	return ok;
}
