#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	// TODO: do args validation

	BitcoinExchange bc;

	if (argc == 2)
		bc.print_exchange_rate_from_input(argv[1]);
}
