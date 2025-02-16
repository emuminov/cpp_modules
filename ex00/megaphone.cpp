#include <iostream>
#include <algorithm>
#include <string>

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	std::string result = argv[1];
	for (int i = 2; i < argc; i++)
	{
		result += argv[i];
	}
	std::transform(result.begin(), result.end(), result.begin(), ::toupper);
	std::cout << result << std::endl;
	return 0;
}
