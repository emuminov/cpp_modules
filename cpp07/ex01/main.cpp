#include "iter.hpp"
#include <string>

void add_number(std::string& str, int i) {
	str += (i + '0');
}

void test_iter() {
	{
		const int arr_len = 9;
		int arr[arr_len] = {0};
		print_arr(arr, arr_len);
		iter(arr, arr_len, inc);
		iter(arr, arr_len, inc);
		iter(arr, arr_len, inc);
		print_arr(arr, arr_len);
	}
	{
		const int arr_len = 2;
		float arr[arr_len] = {0.05, 0.1};
		print_arr(arr, arr_len);
		iter(arr, arr_len, inc);
		print_arr(arr, arr_len);
	}
	{
		const int arr_len = 3;
		std::string arr[arr_len] = {
			"goblin number ",
			"goblin number ",
			"goblin number ",
		};
		print_arr(arr, arr_len);
		iter(arr, arr_len, add_number);
		print_arr(arr, arr_len);
	}
}

int main(void) {
	test_iter();
	return 0;
}
