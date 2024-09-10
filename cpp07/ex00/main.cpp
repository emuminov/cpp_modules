#include "whatever.hpp"
#include <cassert>
#include <iostream>

void subject_tests() {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void my_tests() {
	{
		int v1 = 0;
		int v2 = 1;
		int res = max(v1, v2);
		assert(res == v2);
		std::cout << "v1: " << v1 << "\n";
		std::cout << "v2: " << v2 << "\n";
		std::cout << "max(v1, v2): " << res << "\n";
		std::cout << "===\n";
	}
	{
		int v1 = 0;
		int v2 = 1;
		int res = min(v1, v2);
		assert(res == v1);
		std::cout << "v1: " << v1 << "\n";
		std::cout << "v2: " << v2 << "\n";
		std::cout << "min(v1, v2): " << res << "\n";
		std::cout << "===\n";
	}
	{
		int v1 = 0;
		int v2 = 0;
		const int& res = max(v1, v2);
		assert(&res == &v2);
		std::cout << "v1: " << v1 << "\n";
		std::cout << "v2: " << v2 << "\n";
		std::cout << "min(v1, v2): " << res << "\n";
		std::cout << std::boolalpha << "&res == &v2: " << (&res == &v2) << "\n";
		std::cout << "===\n";
	}
	{
		int v1 = 0;
		int v2 = 0;
		const int& res = min(v1, v2);
		assert(&res == &v2);
		std::cout << "v1: " << v1 << "\n";
		std::cout << "v2: " << v2 << "\n";
		std::cout << "min(v1, v2): " << res << "\n";
		std::cout << std::boolalpha << "&res == &v2: " << (&res == &v2) << "\n";
		std::cout << "===\n";
	}
	{
		int v1 = 0;
		int v2 = 1;
		std::cout << "v1: " << v1 << "\n";
		std::cout << "v2: " << v2 << "\n";
		swap(v1, v2);
		assert(v1 == 1);
		assert(v2 == 0);
		std::cout << "swap(&v1, &v2)" << "\n";
		std::cout << "v1: " << v1 << "\n";
		std::cout << "v2: " << v2 << "\n";
	}
}

int main(void) {
	subject_tests();
	std::cout << "----------------------\n";
	my_tests();
}
