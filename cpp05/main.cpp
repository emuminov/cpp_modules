#include "Bureaucrat.hpp"
#include <iostream>

int main (void) {
	// will be normal
	try {
		Bureaucrat b1("Daniel", 1);
		Bureaucrat b2("Bob", 150);
		b1.dereaseGrade();
		b2.increaseGrade();
		std::cout << b1.getName() << "'s grade was decreased to " << b1.getGrade() << '\n';
		std::cout << b2.getName() << "'s grade was increased to " << b2.getGrade() << '\n';
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	// will throw
	try {
		Bureaucrat b3("Cheater", 0);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	// will throw
	try {
		Bureaucrat b1("Daniel", 1);
		b1.increaseGrade();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	// will throw
	try {
		Bureaucrat b2("Bob", 150);
		b2.dereaseGrade();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
