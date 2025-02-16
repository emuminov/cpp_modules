#include <cmath>
#include <iostream>

int main(int argc, char** argv) {
	(void)argc;
	int n = atoi(argv[1]);
	int number = round((pow(2, n + 1) + pow(-1, n)) / 3);
	std::cout << number << "\n";
}
