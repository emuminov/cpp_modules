#include "RNP.hpp"
#include <algorithm>
#include <iostream>

const std::string RNP::s_valid_token_chars = "0123456789+-/*";

RNP::RNP() : m_data(std::stack<char>()) { return; }

RNP::RNP(const RNP& rnp) : m_data(std::stack<char>(rnp.m_data)) { return; }

RNP& RNP::operator=(const RNP& rnp) {
	if (this == &rnp)
		return *this;
	m_data = rnp.m_data;
	return *this;
}

RNP::~RNP() { return; }

int RNP::solve(const std::string& input) {
	if (_parse_input(input) == error)
	{
		std::cerr << "Error\n";
		return error;
	}
	if (_resolve_equation() == error)
	{
		std::cerr << "Error\n";
		return error;
	}
	return ok;
}

enum RNP::e_status RNP::_parse_input(const std::string& input) {
	std::string reversed_string(input);
	std::reverse(reversed_string.begin(), reversed_string.end());
	size_t start_pos = 0;
	size_t end_pos = reversed_string.find(' ');
	std::string token("");
	while (end_pos != std::string::npos) {
		token = reversed_string.substr(start_pos, end_pos - start_pos);
		if (token.length() != 1 || !_is_valid_token(token))
			return error;
		else
			m_data.push(token[0]);
		start_pos = end_pos + 1;
		end_pos = reversed_string.find(' ', start_pos);
	}
	token = reversed_string.substr(start_pos);
	if (token.length() != 1 || !_is_valid_token(token))
		return error;
	else
		m_data.push(token[0]);
	if (m_data.size() == 0)
		return error;
	return ok;
}

enum RNP::e_status RNP::_resolve_equation() {
	std::stack<int> res((std::stack<int>()));
	while (!m_data.empty()) {
		char token = m_data.top();
		m_data.pop();
		if (isdigit(token)) {
			res.push(token - '0');
		} else {
			int n1;
			int n2;
			switch(token) {
				case '+':
					if (res.size() < 2)
						return error;
					n1 = res.top();
					res.pop();
					n2 = res.top();
					res.pop();
					res.push(n2 + n1);
					break;
				case '-':
					if (res.size() < 2)
						return error;
					n1 = res.top();
					res.pop();
					n2 = res.top();
					res.pop();
					res.push(n2 - n1);
					break;
				case '/':
					if (res.size() < 2)
						return error;
					n1 = res.top();
					res.pop();
					n2 = res.top();
					res.pop();
					res.push(n2 / n1);
					break;
				case '*':
					if (res.size() < 2)
						return error;
					n1 = res.top();
					res.pop();
					n2 = res.top();
					res.pop();
					res.push(n2 * n1);
					break;
				default:
					return error;
			}
		}
	}
	if (res.size() > 1)
		return error;
	std::cout << res.top() << "\n";
	return ok;
}

bool RNP::_is_valid_token(const std::string& str) const {
	return str.find_first_not_of(s_valid_token_chars) == std::string::npos;
}
