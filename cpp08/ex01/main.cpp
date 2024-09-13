#include "Span.hpp"
#include <iostream>

int main(void) {
	Span sp(8);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(11);
	sp.addNumber(1);
	sp.addNumber(21);
	sp.addNumber(17);
	sp.addNumber(9);
	std::cout << sp << "\n";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
