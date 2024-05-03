#include <iostream>
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
	for (unsigned long i = 0; i < result.size(); i++)
	{
		if (result[i] >= 'a' && result [i] <= 'z')
			result[i] -= 32;
	}
	std::cout << result << std::endl;
	return 0;
}
