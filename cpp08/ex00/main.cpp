#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main (void) {
	{
		std::vector<int> vec(10, 3);
		int value_to_find1 = 2;
		int value_to_find2 = 4;
		vec[2] = value_to_find1;
		std::vector<int>::const_iterator found_result = easyfind(vec, value_to_find1);

		if (found_result == vec.end())
			std::cout << "value " << *found_result << " was not found in the vector...\n";
		else
			std::cout << "value " << *found_result << " was found in the vector!\n";

		std::vector<int>::const_iterator non_found_result = easyfind(vec, value_to_find2);
		if (non_found_result == vec.end())
			std::cout << "value " << value_to_find2 << " was not found in the vector...\n";
		else
			std::cout << "value " << value_to_find2 << " was found in the vector!\n";
	}
	std::cout << "===\n";
	{
		std::list<int> lst(10, 3);
		int value_to_find1 = 2;
		int value_to_find2 = 4;
		lst.push_back(value_to_find1);

		std::list<int>::const_iterator found_result = easyfind(lst, value_to_find1);
		if (found_result == lst.end())
			std::cout << "value " << *found_result << " was not found in the list...\n";
		else                                      
			std::cout << "value " << *found_result << " was found in the list!\n";

		std::list<int>::const_iterator non_found_result = easyfind(lst, value_to_find2);
		if (non_found_result == lst.end())
			std::cout << "value " << value_to_find2 << " was not found in the list...\n";
		else
			std::cout << "value " << value_to_find2 << " was found in the list!\n";
	}
	return 0;
}
