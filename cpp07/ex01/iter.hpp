#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
template<typename T>
void iter(T* arr, int len, void (fn)(T*, int)) {
	if (!arr)
		return;
	for (int i = 0; i < len; i++) {
		fn(&arr[i], i);
	}
}

template<typename T>
void iter(T* arr, int len, void (fn)(T*)) {
	if (!arr)
		return;
	for (int i = 0; i < len; i++) {
		fn(&arr[i]);
	}
}

template<typename T>
void print_arr(T* arr, int len) {
	std::cout << "[";
	for (int i = 0; i < len; i++) {
		std::cout << arr[i];
		if (i != (len - 1))
			std::cout << ", ";
	}
	std::cout << "]\n";
}

template<typename T>
void inc(T* ptr_to_incrementable) {
	if (ptr_to_incrementable)
		(*ptr_to_incrementable)++;
}

#endif
