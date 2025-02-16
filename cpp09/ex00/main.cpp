#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: ./btc [input_file]\n";
		return 1;
	}

	BitcoinExchange bc;
	return bc.print_exchange_rate_from_input(argv[1]);
}
